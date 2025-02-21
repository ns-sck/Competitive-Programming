#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<vector<int>>
#define mii map<int, int>
#define ar array
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
const int MOD = 1e9+7;
const int _max = 1e3;
char grid[_max][_max];
bool vis[_max][_max];
char ss[_max][_max];
int32_t main() {

    ios;
    int n, m; cin >> n >> m;
    ar<int, 2> src;
    ar<int, 2> dst;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
                src = {i, j};
            else if (grid[i][j] == 'B')
                dst = {i, j};
            else if (grid[i][j] == '#')
                vis[i][j] = true;
        }
    queue<pair<int, int>> q;
    bool found = false;
    q.push({src[0], src[1]});
    vis[src[0]][src[1]] = true;
    while (!q.empty()) {
        auto a = q.front();
        int i = a.first;
        int j = a.second;
        q.pop();
        if (grid[i][j] == 'B') {
            cout << "YES\n";
            found = true;
            break;
        }
        if (i && !vis[i-1][j]) {
            vis[i-1][j] = true;
            ss[i-1][j] = 'U';
            q.push({i-1, j});
        }
        if (i < n-1 && !vis[i+1][j]) {
            vis[i+1][j] = true;
            ss[i+1][j] = 'D';
            q.push({i+1, j});
        }
        if (j && !vis[i][j-1]) {
            vis[i][j-1] = true;
            ss[i][j-1] = 'L';
            q.push({i, j-1});
        }
        if (j < m-1 && !vis[i][j+1]) {
            vis[i][j+1] = true;
            ss[i][j+1] = 'R';
            q.push({i, j+1});
        }
    }
    if (found) {
        string s = "";
        int ni = dst[0];
        int nj = dst[1];
        int ans = 0;
        s += ss[ni][nj];
        while (grid[ni][nj] != 'A') {
            if (ss[ni][nj] == 'D') {
                ni = ni-1;
            }
            else if (ss[ni][nj] == 'U') {
                ni = ni+1;
            }
            else if (ss[ni][nj] == 'R') {
                nj = nj-1;
            }
            else if (ss[ni][nj] == 'L') {
                nj = nj+1;
            }
            ++ans;
            s += (ss[ni][nj]);
        }
        cout << ans << '\n';
        for (int i = ans-1; ~i; --i)
            cout << s[i];
    
        return 0;
    }
    cout << "NO\n";
    return 0;
}
