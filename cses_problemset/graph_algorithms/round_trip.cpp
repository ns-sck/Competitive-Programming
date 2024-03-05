#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<vector<int>>
#define mii map<int, int>
const int MOD = 1e9+7;
const int _max = 2e5+1;
vi adj[_max];
bool vis[_max];
vi cnt(_max, 1e9);
vi par(_max);
bool b = false;
int ansn = 0;
int ans = 0;

void dfs(int node, int step) {
    if (vis[node])
        return;
    vis[node] = true;
    cnt[node] = step;
    for (auto neigh : adj[node]) {
        if (!b && cnt[neigh] + 1 < step) {
            ansn = neigh;
            ans = step + 1 - cnt[neigh] + 1;
            par[neigh] = node;
            b = true;
            return;
        }
        if (!vis[neigh]) {
            par[neigh] = node;
            dfs(neigh, step+1);
        }
    }
}
int32_t main() {

    int n, m;
    cin >> n >> m;
    
    while (m--) {
        int a, b; 
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) 
            continue;
        dfs(i, 0);
        if (b) {
            int a = par[ansn];
            cout << ans << '\n';
            cout << ansn << ' ';
            while (a != ansn) {
                cout << a << ' ';
                a = par[a];
            }
            cout << ansn;
            return 0;
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}
