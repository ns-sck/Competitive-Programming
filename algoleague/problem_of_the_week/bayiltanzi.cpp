#include <bits/stdc++.h>
using namespace std;

template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...); cout << '\n';}

#define int long long
#define ll long long
#define pi pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpi vector<pi>
#define pb push_back
#define ar array
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const ll MOD = 1e9+7;
const ll INF = 1e18;
const ll MAX = 2e5+1;

void solve() {
    int K, X;
    cin >> K >> X;

    int ans = 0;
    priority_queue<int, vi, greater<>> pq;
    ++K;
    for (int i = 0; i < K; ++i) {
        pq.push(X / K);
    }   

    for (int i = 0; i < X % K; ++i) {
        int x = pq.top();
        pq.pop();
        ++x;
        pq.push(x);
    }

    while (pq.size()) {
        int x = pq.top();
        pq.pop();
        ans += x * x;
    }

    cout << ans << '\n';
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}