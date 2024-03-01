#pragma optimize("")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int MOD = 1e9+7;
const int MAXN = 2e5 + 1;

vector<pair<long long,long long>> adj[MAXN];
long long dist[MAXN];
int32_t main() {
    ios;

    int node_sayisi, kenar_sayisi;
    cin>> node_sayisi >> kenar_sayisi;
    int start, end;
    cin>> start >> end;
    while(kenar_sayisi--){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    priority_queue<pair<long long ,long long>, vector<pair<long long,long long>>, greater<>> pq;

    pq.push({0,start});

    for (int i =1 ;i< MAXN;i++){
        dist[i] = 1e18;
    }

    while(!pq.empty()){
        auto curr_element = pq.top();
        pq.pop();
        long long node = curr_element.second;
        long long cost = curr_element.first;
        if(cost > dist[node]){
            continue;
        }
        dist[node] = cost;

        for(auto komsu: adj[node]){
            if(cost+komsu.second< dist[komsu.first]){
                pq.push(make_pair(cost+komsu.second, komsu.first));
            }

        }
    }
    if(dist[end]==1e18){
        cout<<-1<<endl;
    }else{
        cout<<dist[end]<<endl;
    }
    



    return 0;
}