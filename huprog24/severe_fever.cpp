#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define vii vector<vector<int>>
#define pii pair<int, int>
#define ar array

const int INF = 1e18;
const int MOD = 1e9+7;
const int _max = 6e3+1;

vector<set<int>> adj(_max);
map<pii, int> mp;
map<pii, bool> mp2;
void dfs(int src, int step, int node) {
    if (step == 2) {
        mp[{src, node}]++;
        return;
    }
    for (auto x : adj[node]) {
        if (x != src)
            dfs(src, step+1, x);
    }
}

int comb(int n, int m) {
    int ans = 1;
    for (int i = 1; i <= m; ++i) {
        ans *= (n-i+1);
        ans /= i;
    }
    return ans;
}

int32_t main() {
	
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        if (u != v)
            adj[u].insert(v);
    }

    for (int i = 1; i <= n; ++i) {
        dfs(i, 0, i);
    }
    int ans = 0;
    for (auto p : mp) {
        if (p.second >= k) {
            ans += comb(p.second, k);
        }
    }
    cout << ans;
    return 0;
}
