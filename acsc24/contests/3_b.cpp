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
const ll MAX = 2e5+1;

int w[MAX];
int val[MAX];
int dp[10001][1001];
map<int, int> prs;
bool ok[MAX];
void solve() {
    int N, X, C;
    cin >> N >> X >> C;
    for (int i = 1; i <= N; ++i) cin >> w[i];
    for (int i = 1; i <= N; ++i) cin >> val[i];
    while (X--) {
        int u, v;
        cin >> u >> v;
        if (u > v) swap(u, v);
        prs[u] = v;
        prs[v] = u;
    }
    vi v;
    for (int i = 1; i <= N; ++i) {
        if (!prs.count(i)) {
            v.pb(i);
        }
    }
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j <= C; ++j) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if (j >= w[v[i]]) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-w[v[i]]] + val[v[i]]);
            }
        }
    }
    int k = (N-v.size())>>1;
    for (int i = v.size(); i < k+v.size(); ++i) {
        auto it = prs.begin();
        int u = it->first, v = it->second;
        for (int j = 0; j <= C; ++j) {
            int mxv = max(i ? dp[i-1][j] : 0, dp[i][j-1]);
            if (j >= w[u]) {
                mxv = max(mxv, (i ? dp[i-1][j-w[u]] : 0) + val[u]);
            }
            if (j >= w[v]) {
                mxv = max(mxv, (i ? dp[i-1][j-w[v]] : 0) + val[v]);
            }
            dp[i][j] = mxv;
        }
        auto it2 = prs.find(v);
        prs.erase(it);
        prs.erase(it2);
    }
    cout << dp[v.size()+k-1][C];
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
