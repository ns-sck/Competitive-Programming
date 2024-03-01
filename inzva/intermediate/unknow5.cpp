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
int n,m;
vector<pair<int,pair<int,int>>> edgeList;
vector<int> parent;
vector<int> size;


// kruskal's mst
/*

*/


int atabul(int u) {
    if ( parent[u] == u ) return u;
    parent[u] = atabul(parent[u]);
    return parent[u];
}

void uunion(int u, int v)  {
    
    int parentU = atabul(u);
    int parentV = atabul(v);
    
    if ( size[parentU] < size[parentV] ) {
        parent[parentU] = parentV;
        size[parentV] += size[parentU];
    }else {
        parent[parentV] = parentU;
        size[parentU] += size[parentV];
    }
}

int main() {
    
    
    
    cin >> n >> m;
    parent.resize(n+1);
    size.resize(n+1);
    for (int i = 1; i <= n; i++) {
        parent[i] = i; 
        size[i] = 1;
    }
    
    for (int i = 0; i < m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        
        edgeList.push_back({w,{u,v}});
    }
    
    sort(edgeList.begin(), edgeList.end());
    
    int numOfEdges = 0;
    int totalPath = 0;
    for (int i = 0; i < m; i++) {
        
        // break if found enough #edges
        if ( numOfEdges == n-1 ) break;
        
        int w = edgeList[i].first;
        int u = edgeList[i].second.first;
        int v = edgeList[i].second.second;
        
        // if join u and f
        if ( atabul(u) != atabul(v) ) {
            totalPath += w;
            uunion(u,v);
        }
    }
    cout << totalPath << '\n';
    
    
    return 0;
}