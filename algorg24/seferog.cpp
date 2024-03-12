#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define vii vector<vector<int>>
#define pii pair<int, int>
#define ar array

const int INF = 1e18;
const int MOD = 998244353;
const int _max = 1e5+1;
vi adj[_max];
vi clr(_max, 0);
vector<bool> vis(_max, 0);

int fastPow(int base, int exp) {
    int ans = 1;
    for(int i = 0; i < 45; i++) {
        if((1LL << i) & exp)
            ans *= base;
        base *= base;
        base %= MOD;
        ans %= MOD;
    }
    return ans;
}

int32_t main() {
	
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {

            queue<int> q;
            q.push(i);
            clr[i] = 1;
            while (q.size()) {
                int node = q.front();
                q.pop();
                for (auto neigh : adj[node]) {
                    if (clr[neigh] == clr[node]) {
                        cout << 0;
                        return 0;
                    }
                    if (!vis[neigh]) {
                        vis[neigh] = true;
                        q.push(neigh);
                        clr[neigh] = -clr[node];
                    }
                }
            }
            ++ans;
        }
    }
    
    cout << fastPow(2, ans);
    return 0;
}
