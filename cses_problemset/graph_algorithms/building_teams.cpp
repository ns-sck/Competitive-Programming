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
vii adj(_max, vi());
vi teams(_max);
vector<bool> vis(_max, false);
bool b = true;
void dfs(int node) {
    if (vis[node])
        return;
    vis[node] = true;
    for (auto neigh : adj[node]) {
        if (teams[neigh] == teams[node]) {
            b = false;
            break;
        }
        teams[neigh] = (-1) * teams[node];
        dfs(neigh);
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
    for (int i = 1 ; i <= n; ++i) {
        if (!vis[i]) {
            teams[i] = 1;
            dfs(i);
        }
    }
    if (!b) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        if (teams[i] == -1) 
            teams[i] = 2;
        cout << teams[i] << ' ';
    }
    return 0;
}
