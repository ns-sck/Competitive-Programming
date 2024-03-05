#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<vector<int>>
#define mii map<int, int>
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
const int MOD = 1e9+7;
const int mxN = 1e3;
bool vis[mxN][mxN];
int32_t main() {

    ios;
    int n, m; cin >> n >> m;
    int ans = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            char c; cin >> c;
            if (c == '#')
                vis[i][j] = true;
        }
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            if (!vis[i][j]) {
                ++ans;
                queue<pair<int, int>> q;
                q.push({i, j});
                vis[i][j] = true;
                while (!q.empty()) {
                    auto p = q.front();
                    q.pop();
                    int r = p.first;
                    int c = p.second;

                    if (r && !vis[r-1][c]) {
                        vis[r-1][c] = true;
                        q.push({r-1,c});
                    }
                    if (c && !vis[r][c-1]) {
                        vis[r][c-1] = true;
                        q.push({r,c-1});
                    }
                    if (r < n-1 && !vis[r+1][c]) {
                        vis[r+1][c] = true;
                        q.push({r+1,c});
                    }
                    if (c < m-1 && !vis[r][c+1]) {
                        vis[r][c+1] = true;
                        q.push({r,c+1});
                    }
                }
            }
        }
    cout << ans;
    return 0;
}
