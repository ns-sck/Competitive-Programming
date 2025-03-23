#include "bits/stdc++.h"
#define ll long long
using namespace std;
const int N = 2e5+5;
bool ban[N];
int sub[N];
vector<int> adj[N];
 
void precompute(int nd, int pr){
    sub[nd] = 1;
    for (auto to: adj[nd]){
        if (to == pr or ban[to])
            continue;
        precompute(to, nd);
        sub[nd] += sub[to];
    }
}
 
int centroid(int nd, int pr, int sz){
    for (auto to: adj[nd]){
        if (to == pr or ban[to])
            continue;
        if (sub[to] > sz/2)
            return centroid(to, nd, sz);
    }
    return nd;
}
 
int n, k;
ll answer;
map<int,int> cnt;
 
void upd(int nd, int pr, int r = 1){
    cnt[r] += 1;
    for (auto to: adj[nd]){
        if (to == pr or ban[to])
            continue;
        upd(to, nd, r+1);
    }
}
 
void get(int nd, int pr, int r = 1){
    answer += cnt[k - r];
    for (auto to: adj[nd]){
        if (to == pr or ban[to])
            continue;
        get(to, nd, r+1);
    }
}
void solve(int l){
    cnt.clear();
    for (auto to: adj[l]){
        if (ban[to])
            continue;
        get(to, l);
        upd(to, l);
    }
    //u is l
    answer += cnt[k];
}
 
void build(int nd, int par_centr){
    precompute(nd, -1);
    int centr = centroid(nd, -1, sub[nd]);
    ban[centr] = 1;
 
    solve(centr);
 
    for (auto to: adj[centr])
        if (!ban[to])
            build(to, centr);
}

 
int main(){
    // freopen("file.in", "r", stdin);
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // bridge(1, -1);
    // int x = 0, y = 0;
    // for (int i = 1; i <= n; ++i) {
    //     for (auto v : adj2[i]) {
    //         if (!(mp[{i, v}] || mp[{v, i}])) {
    //             x = i, y = v;
    //             continue;
    //         }
    //     }
    // }
    // for (int i = 1; i <= n; ++i) {
    //     for (auto v : adj2[i]) {
    //         if ((i == x && y == v) || (i == y && v == x)) continue;
    //         adj[i].emplace_back(v);
    //     }
    // }
    build(1, -1);
    // vector<int> dis1(n + 1), dis2(n + 1);
    // int start;
    // vector<int> vis(n + 1);
    // int len = 0;
    // auto dfs = [&](auto&& self, int u, int p, int d, vector<int>& dis) -> void {
    //     dis[d]++;
    //     for (auto& v : adj[u]) {
    //         if (v == p || v == start || vis[v]) continue;
    //         self(self, v, u, d + 1, dis);
    //     }
    // };
    // auto dfs2 = [&](auto&& self, int u, int p, int o, int d) -> bool {
    //     for (auto v : adj[u]) {
    //         if (v == p) continue;
    //         if (v == o) {
    //             vis[u] = 1;
    //             len = d;
    //             return 1;
    //         }
    //         if (self(self, v, u, o, d + 1)) {
    //             vis[u] = 1;
    //             return 1;
    //         }
    //     }
    // };
    // dfs2(dfs2, x, -1, y, 0);
    // vis[y] = 1;
    // start = y;
    // dfs(dfs, x, -1, 0, dis1);
    // start = x;
    // dfs(dfs, y, -1, 0, dis2);
    // for (int i = 0; i < k; ++i) {
    //     answer += dis1[i] * dis2[k - i - 1];
    // }
    // for (int i = 0; i < len; ++i) {
    //     answer += dis1[k - 1 - i - 1];
    //     answer += dis2[k - 1 - i - 1];
    // }
    // if (len + 1 >= k) {
    //     answer += len + 1;
    // }
    printf("%lld\n", answer);
}