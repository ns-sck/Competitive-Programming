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
const ld EPS = 1e-9; 

vi adj[MAX];
int in[MAX];
void solve() {
    int N, M;
    cin >> N >> M;
    while (M--) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        ++in[v];
    }
    bool b = 1;
    int c = 0;
    queue<int> q;
    for (int i = 1; i <= N; ++i) {
        if (in[i] == 0) {
            if (c++ > 0) b = 0;
            q.push(i);
        }
    }
    vi top;
    while (q.size()) {
        int u = q.front();
        q.pop();
        top.pb(u);
        int k = 0;
        for (auto& v : adj[u]) {
            if (--in[v] == 0) {
                if (k++ > 0) b = 0;
                q.push(v);
            }
        }
    }
    if (top.size() != N || !b) {
        cout << "The duels should continue.\n";
    } else {
        cout << "The duels should stop.\n";
        vi ans(N+1);
        for (int i = 0; i < N; ++i) {
            int u = top[i];
            ans[u] = i+1;
        }
        for (int i = 1; i <= N; ++i) cout << ans[i] << ' ';
    }
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
