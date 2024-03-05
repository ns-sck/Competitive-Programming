#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<vector<int>>
#define mii map<int, int>
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
const int MOD = 1e9+7;
const int _max = 2e5+1;
vi adj[_max];
int par[_max];
int vis[_max];
int32_t main() {

    ios;
    int n, m; cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<int> q;
    q.push(1);
    vis[1] = true;
    par[1] = -1;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        if (node == n)
            break;
        for (auto neigh : adj[node]) {
            if (!vis[neigh]) {
                par[neigh] = node;
                vis[neigh] = true;  
                q.push(neigh);
            }
        }
    }
    if (vis[n]) {
        int a = n;
        int ans = 1;
        while (par[a] != -1) {
            ++ans;
            a = par[a];
        }
        a = n;
        vector<int> v;  
        cout << ans << '\n';
        while (par[a] != -1) {
            v.push_back(a);
            a = par[a];
        }
        v.push_back(1);
        for (int i = v.size() - 1; ~i; --i) {
            cout << v[i] << ' ';
        }
    } else {
        cout << "IMPOSSIBLE";
    }
    return 0;
}
