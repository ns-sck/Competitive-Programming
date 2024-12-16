#include <bits/stdc++.h>
using namespace std;

template<typename... T>
void dbg(T&&... args) { ((cout << args << " "), ...); cout << '\n';}

#define int long long

constexpr int MOD = 1e9+7;
constexpr int MAX = 2e5+1;

struct BIT2D {
    vector<vector<int>> bit;
    int n, m; // give + 1

    BIT2D(int n, int m) : n(n), m(m) {
        bit.assign(n, vector<int>(m, 0));
    }

    int sum(int x, int y) {
        int ret = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
            for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
                ret += bit[i][j];
        return ret;
    }

    void add(int x, int y, int delta) {
        for (int i = x; i < n; i = i | (i + 1))
            for (int j = y; j < m; j = j | (j + 1))
                bit[i][j] += delta;
    }
};

void solve() {
    int N, M;
    cin >> N >> M;
    BIT2D bit(N + 1, M + 1);
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            int x; cin >> x;
            bit.add(i, j, x);
        }
    }
    while (1) {
        int x, y, a;
        cin >> x >> y >> a;
        bit.add(x, y, a);
        int z = bit.sum(x, y);
        cout << z << '\n';
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