#pragma optimize("")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int MOD = 1e9+7;
const int MAXN = 2e5 + 1;

vector<pair<int,int>> adj[MAXN];
bool visited[MAXN];
int32_t main() {
    ios;

    int node_sayisi, kenar_sayisi;
    cin>>node_sayisi>>kenar_sayisi;
    while(kenar_sayisi--){
        int u, v, w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    int src = 1;
    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<>> pq;
    for(auto komsular: adj[src]){
        pq.push({komsular.second,{src, komsular.first}});
    }
    long long  total_cost = 0;

    while(!pq.empty()){
        auto node = pq.top();
        pq.pop();
        int cost = node.first;
        int u = node.second.first;
        int v = node.second.second;

        if(visited[u] && visited[v]){
            continue;
        }
        total_cost+=cost;
        visited[u] = true;
        visited[v] = true;
        for(auto komsular: adj[u]){
            pq.push({komsular.second,{u, komsular.first}});
        }
        for(auto komsular: adj[v]){
            pq.push({komsular.second,{v, komsular.first}});
        }
    }
    cout<<total_cost<<endl;




    return 0;
}