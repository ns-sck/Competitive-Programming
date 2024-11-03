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
    map<int, int> mp;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            int a; cin >> a;
            int x = N - i + j;
            mp[x] = min(mp[x], a);
        }
    }

    // 1 -5
    // 2 -3
    // 3 -2

    int ans = 0;
    for (auto [x, y] : mp) {
        ans -= y;
    }

    put(ans);
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