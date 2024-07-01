#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define ld long double
#define pi pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpi vector<pi>
#define pb push_back
#define ar array
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const ll MOD = 1e9+7;
const ll INF = 1e18;
const ll MAX = 20;
const ld EPS = 1e-9; 
int N, M, K, l, ans = 0;
int g[MAX][MAX];
map<int, int> dp[MAX];
void dfs(int i, int j, int t) {
    t ^= g[i][j];
    if (i+j == l) {
        ++dp[i][t];
        return;
    }
    if (i+1 < N) dfs(i+1, j, t);
    if (j+1 < M) dfs(i, j+1, t);
}
void dfs2(int i, int j, int t, int c = 0) {
    t ^= g[i][j];
    if (c == N+M-2-l) {
        auto it = dp[i].find(t^g[i][j]^K);
        if (it != dp[i].end()) ans += it->second;
        return;
    }
    if (i) dfs2(i-1, j, t, c+1);
    if (j) dfs2(i, j-1, t, c+1);
}
void solve() {
    cin >> N >> M >> K;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j) {
            cin >> g[i][j];
        }
    l = (N+M-2)>>1;
    dfs(0, 0, 0);
    dfs2(N-1, M-1, 0);
    cout << ans << '\n';
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
