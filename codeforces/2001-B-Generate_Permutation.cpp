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
    int N; cin >> N;
    if (N % 2 == 0) {
        cout << -1 << '\n';
        return;
    }
    vi v(N);
    int x = 1;
    for (int i = 0; i < N; i += 2) {
        v[i] = x++;
    }
    x = N;
    for (int i = 1; i < N; i += 2) {
        v[i] = x--;
    }
    for (int& a : v) cout << a << ' ';
    cout << '\n';
}

signed main () {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}
