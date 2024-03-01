#include <iostream>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <tuple>
#include <set>
#include <queue>

/*
6 6
1 2
1 3
4 3
3 5
5 6
2 6
*/
using namespace std;

vector<bool> vis;    
vector<vector<int>> adjList;
int n,m;

void dfs(int u, vector<int>& vec) {
    vis[u] = true;
    for (int v : adjList[u] ) {
        if ( !vis[v] ) {
            dfs(v, vec);
        }
    }
    vec.push_back(u);
}

int main() {
    
    cin >> n >> m;
    adjList.resize(n+1);
    vis.resize(n+1,false);
    
    // undirected, unweighted
    for (int i = 0; i < m; i++) {
        int u,v; cin >> u >> v;
        adjList[u].push_back(v);
        //adjList[v].push_back(u);
    }
    
    vector<int> vec;
    for ( int i = 1; i <=n ; i++ ) {
        if ( !vis[i] ) {
            dfs(i, vec);
        }
    }
    
    reverse(vec.begin(), vec.end());
    for ( auto i : vec) {
        cout << i << ' ';
    }
    
    return 0;
}