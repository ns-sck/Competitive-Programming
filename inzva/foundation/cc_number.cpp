#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int MOD = 1e9+7;
const int MAXN = 1e5 + 1;

vector<int> adj[MAXN];
int visited[MAXN];

void dfs(int node){
    if(visited[node]){
        return;
    }
    visited[node] = true;
    for(int komsu: adj[node]){
        dfs(komsu);
    }
}
int32_t main() {
    ios;

    int node_sayisi, kenar_sayisi;
    cin>> node_sayisi >> kenar_sayisi;
    while(kenar_sayisi--){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int component_sayisi = 0; 
    for(int i=1; i<=node_sayisi; i++){
        if(!visited[i]){
            dfs(i);
            component_sayisi++;
        }
    }
    cout<<component_sayisi<<endl;



    return 0;
}