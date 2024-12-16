#include <bits/stdc++.h>
using namespace std;

#define int long long

constexpr int MOD = 1e9+7;
constexpr int MAX = 2e5+1;

int N, Q, x, k, par[MAX][31];

void solve() {
    cin >> N >> Q;
    for (int i = 1; i <= N; ++i) {
        cin >> par[i][0];
    }
    for (int i = 1; i <= 30; ++i) {
        for (int j = 1; j <= N; ++j) {
            par[j][i] = par[par[j][i - 1]][i - 1];
        }
    }
    while (Q--) {
        cin >> x >> k;
        for (int i = 30; ~i; --i) {
            if (k & (1 << i)) {
                x = par[x][i];
            }
        }   
        cout << x << '\n';
    }
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}