#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<vector<int>>
#define mii map<int, int>
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
const int MOD = 1e9+7;
const int _max = 2e5+1;
bool vis[_max];
vector<int> adj[_max];

void dfs(int node) {
    vis[node] = 1;
    for(int neigh : adj[node]) {
        if(!vis[neigh]) {
            dfs(neigh);
        }
    }
}

int32_t main() {

    ios;
    int n, m; cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vi ans;
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            ans.push_back(i);
            dfs(i);
        }
    }
    cout << ans.size() - 1 << '\n';
    for (int i = 0; i < ans.size() - 1; ++i) {
        cout << ans[i] << ' ' << ans[i+1] << '\n';
    }
    return 0;
}
