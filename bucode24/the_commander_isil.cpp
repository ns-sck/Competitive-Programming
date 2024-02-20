//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>
using namespace std;

bool dfs(int v, vector<vector<int>>& adj, vector<bool>& visited, int parent) {
    visited[v] = true;

    for (int i : adj[v]) {
        if (!visited[i]) {
            if (dfs(i, adj, visited, v))
                return true;
        } else if (i != parent) {
            return true;
        }
    }
    return false;
}

bool isCyclic(vector<vector<int>>& adj, int n) {
    vector<bool> visited(n+1, false);

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            if (dfs(i, adj, visited, -1))
                return true;
        }
    }
    return false;
}

int main() {
// write your code here
    int n, m;
    cin >> n >> m;
    vector<bool> used(n + 1, false);
    vector<int> fr(n + 1, 0);
    vector<vector<int>> adj(n+1, vector<int>(0));
    while (m--) {
        int a, b;
        cin >> a >> b;
        fr[a]++, fr[b]++;
        adj[a].push_back(b);
        adj[b].push_back(a);
        if (fr[a] > 2 || fr[b] > 2) {
            cout << -1 << '\n';
            return 0;
        }
    }

    if(isCyclic(adj, n)) {
        cout << -1 << '\n';
        return 0;
    }
    
    vector<int> ans;
    int last = 1;
    bool moved = false;

    for (int i = 1; i <= n; ++i) {
        if (fr[i] == 2 || used[i]) {
            continue;
        }
        
        bool found = true;
        int node = i;
        while (found) {
            
            ans.push_back(node);
            used[node] = true;
            bool b = false;
            for (auto neigh : adj[node]) {
                if (!used[neigh]) {
                    node = neigh;
                    b = true;
                }
            }
            found = b;
        }
    }

    for (auto& x : ans) {
        cout << x << ' ';
    }
	return 0;
}
