/*5 5
1 2
1 5
2 3
2 4
4 5*/
#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<bool> vis;    
vector<vector<int>> adjList;

int main() {
    
    

    cin >> n >> m;
    adjList.resize(n+1);
    //vis.resize(n+1,false);
    
    // undirected, unweighted
    for (int i = 0; i < m; i++) {
        int u,v; cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // bfs
    queue<pair<int,int>> q;
    vector<char> color(n+1, 'U');
    color[1] = 'K';
    q.push({1,0});
    
    while ( !q.empty() ) {
        
        int u = q.front().first;
        int lvl = q.front().second;
        q.pop();
        
        for ( int v : adjList[u] ) {
            
            if ( color[v] != 'U' ) continue; 
            
            if ( (lvl+1) % 2 == 0 ) {
                color[v] = 'K';
            }else {
                color[v] = 'M';
            }
            q.push({v,lvl+1});
        }
    }
    
    for (int i = 1; i <=n ; i++) {
        cout << color[i] << ' ';
    }
    bool isBipartite = true;
    for ( int i = 1; i <=n ;i++) {
        for ( int j : adjList[i]) {
            if ( color[i] == color[j] ) {isBipartite = false; break;}
            
        }
        if ( !isBipartite ) break;
    }
    
    cout << (isBipartite ? "YES" : "NP") << '\n';
    return 0;
    
    
    
    
    

    return 0;
}   