#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
vector<vector<pair<int,int>>> adj(5e5 + 1, vector<pair<int,int>>(0));
int32_t main() {
    ios;
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> mods(k, 0);
    vector<vector<bool>> b(5e4 + 1, vector<bool>(k, false));
    for (int i = 0; i < k; ++i) {
        cin >> mods[i];
    }
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<>> pq;
    pq.push({0, {1, k - 1}});
    int ans = LLONG_MAX;
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        int node = p.second.first;
        int dis = p.first;
        int count = p.second.second;
        if (dis > ans) {
            continue;
        }
        b[node][count] = true;
        if (node == n) {
            ans = min(ans, dis);
        }
        for (auto& neigh : adj[node]) {
            int newCount = (count + 1) % k;
            if (!b[neigh.first][newCount]) {
                
                pq.push({dis + mods[newCount] * neigh.second, {neigh.first, newCount}});
            }
        }
    }
    cout << ans;
}
