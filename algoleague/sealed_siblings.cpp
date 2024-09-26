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
    int N, K, P;
    cin >> N >> K >> P;

    vi a(N);
    for (int& x : a) cin >> x;

    map<int, priority_queue<pi, vpi, greater<>>> mp;

    for (int i = 0; i < N; ++i) {
        int md = a[i] % P;
        int x = a[i] % K;
        if (!x) x = INF;
        mp[md].push({x, a[i]});
    }

    vi b(N);

    for (int i = 0; i < N; ++i) {
        auto [x, y] = mp[a[i] % P].top();
        mp[a[i] % P].pop();
        b[i] = y;
    }

    for (int& x : b) cout << x << ' ';

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