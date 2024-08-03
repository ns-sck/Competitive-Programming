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
const ll MAX = 1e3+1;

vi adj[MAX];
void solve() {
	int N; cin >> N;
    for (int i = 0; i < N; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].pb(v);
    }
    bool vis[N];
    int ans = N*N;
    for (int i = 0; i < N; ++i) {
        memset(vis, 0, sizeof(vis));
        vi q = {i};
        int j = 0;
        while (j < q.size()) {
            int u = q[j++];
            if (vis[u]) continue;
            --ans;
            vis[u] = 1;
            for (int& v : adj[u]) {
                if (!vis[v]) q.pb(v);
            }
        }
    }
    cout << ans << '\n';
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
