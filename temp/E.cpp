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
    int N, M, Q;
    cin >> N >> M >> Q;

    vvi v(N, vi(M));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> v[i][j];
            if (i) v[i][j] |= v[i-1][j];
        }
    }

    vvi mp(M);
    for (int j = 0; j < M; ++j) {
        for (int i = 0; i < N; ++i) {
            mp[j].pb(v[i][j]);
        }
    }

    while (Q--) {
        int t; cin >> t;
        int lb = 0, ub = N - 1;
        while (t--) {
            int a, b;
            char c;
            cin >> a >> c >> b;
            --a;
            if (c == '>') {
                int idx = upper_bound(all(mp[a]), b) - mp[a].begin();
                lb = max(lb, idx);
            } else {
                auto it = lower_bound(all(mp[a]), b);
                --it;
                int idx = it - mp[a].begin();
                ub = min(ub, idx);
            }
        }

        if (lb <= ub && lb < N) {
            cout << lb + 1 << '\n';
        } else cout << -1 << '\n';
    }


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