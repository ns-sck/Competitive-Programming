#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<vector<int>>
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
const int MOD = 1e9+7;
vii t;
vii grid;
vii grid2;
int n, q;

int32_t main() {

    ios;
    cin >> n >> q;
    t.resize(4*n*n);
    vii grid3(n+1, vi(n+1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> grid3[i][j];
        }
    }
    grid = grid3;
    grid2 = grid;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            grid[i][j] += grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1];
        }
    }
    while (q--) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        int h = 0;
        for (int i = x1; i <= x2; ++i) {
            for (int j = y1; j <= y2; ++j) {
                h = max(h, grid2[i][j]);
            }
        }
        int area = (x2 - x1 + 1) * (y2 - y1 + 1);
        cout << (h * area) - (grid[x2][y2] + grid[x1-1][y1-1] - grid[x2][y1-1] - grid[x1-1][y2]) << '\n'; 
    }
    return 0;
}
