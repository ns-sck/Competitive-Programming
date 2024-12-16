#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int X, M;
    cin >> X >> M;
    // if z == x ^ y
    // y == z ^ x, where z == x * a
    // z ^ x <= z + x
    // for all z <= m - x, there is a solution ans += (m - x) / x
    // for all z > m - x, there is no solution
    // for other two elements where z > m - x && z <= m - x, manual check
    int ans = 0;
    if (M >= X) {
        ans += (M - X) / X;
        int z = M - M % X;
        while (z <= M + X) {
            int y = z ^ X;
            if (y <= M) ++ans;
            z += X;
        }
    }
    // if z == x ^ y
    // y == z ^ x, where z == y * a
    // z ^ x <= z + x
    // if z == y * a, y <= x, otherwise z cannot be >= 2 * y
    // iterate over all y
    for (int i = 1; i <= min(M, X); ++i) {
        int z = i ^ X;
        if (z % i == 0) {
            ++ans;
        }
    }
    // if z == x * a && y * b
    // z == lcm(x, y) * c
    // we know that z < 2 * max(x, y)
    // so it can only happen where x == y
    if (M >= X) {
        --ans;
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