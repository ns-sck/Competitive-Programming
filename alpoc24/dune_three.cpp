#include <bits/stdc++.h>

using namespace std;

#define int long long

int dp[5001][5001];
int val[5001];
vector<vector<int>> adj;

int dfs(int start, int cur, int x, int parent)
{
    auto& ref = dp[start][cur];
    if (ref != -1) return ref;
    int ans = x ^ val[cur], sum = 0;
    vector<int> a, b;
    for (auto& v : adj[cur])
    {
        if (v == parent) continue;
        int c = dfs(start, v, ans, cur);
        int d = dfs(v, v, 0, cur);
        a.push_back(c);
        b.push_back(d);
        sum += d;
    }
    int end = sum + ans;
    for (int i = 0; i < a.size(); i++)
    {
        end = min(end, sum + a[i] - b[i]);
    }
    return dp[start][cur] = end;
} 

signed main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> val[i];
    adj.resize(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(dp, -1, sizeof(dp));
    cout << dfs(1,1,0,1);
	return 0;
}
