#include "bits/stdc++.h"
#define ll long long
using namespace std;
const int N = 1e5+5;
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
    for (int i = 1; i < n; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    build(1, -1);
    printf("%lld\n", answer);
}