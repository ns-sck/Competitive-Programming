#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited){
    if(visited[node]){
        return;
    }
    visited[node] = true;
    for(int neigh: adj[node]){
        dfs(neigh, adj, visited);
    }
}

int32_t main() {
    ios;
    int n;
    cin >> n;
    while (n--) {
        vector<int> v1(1e5 + 1, 0);
        vector<vector<int>> adj(1e5 + 1, vector<int>(0));
        vector<bool> visited(1e5 + 1, true);
        int a;
        cin >> a;
        int b = a;
        int maxEl = INT_MIN;
        bool found = false;
        while (b--) {
            int u, v;
            cin >> u >> v;
            if (u == 1) {
                found = true;
            }
            visited[u] = false;
            visited[v] = false;
            maxEl = max(maxEl, u);
            maxEl = max(maxEl, v);
            adj[u].push_back(v);
            v1[u]++;
            v1[v]--;
        }
        for (int i = 0; i < maxEl; ++i) {
            if (v1[i] != 0) {
                found = false;
                break;
            }
        }
        int c = 0; 
        for(int i = 1; i <= maxEl; i++){
            if(!visited[i]){
                dfs(i, adj, visited);
                c++;
            }
            if (c > 1) {
                break;
            }
        }
        if (c == 1 && found) {
            cout << 1 << '\n';
        } else
            cout << -1 << '\n';
    }
}
