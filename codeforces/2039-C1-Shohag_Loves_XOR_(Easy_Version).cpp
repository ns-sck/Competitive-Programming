#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int X, M;
    cin >> X >> M;
    int ans = 0;
    for (int i = 1; i <= min(M, 2 * X); ++i) {
        int z = i ^ X;
        if (z == 0) continue;
        bool b = 0;
        if (z <= i) {
            if ((i % z) == 0) b = 1;
        }
        if (z <= X) {
            if ((X % z) == 0) b = 1;
        }
        ans += b;
    }
    cout << ans << '\n';
}

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}