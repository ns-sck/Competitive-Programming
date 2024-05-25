#include <bits/stdc++.h>
using namespace std;

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

void solve() {
    int n; cin >> n;
    int a, b, nn = n; 
    cin >> a >> b;
    --a, --b;
    vvi adj(n, vi());
    vi dis_a(n, 1e9), dis_b(n, 1e9);
    while (--nn) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int vx, fnd;
    queue<pi> q;
    q.push({a, 0});
    while (q.size()) {
        auto [u, st] = q.front();
        q.pop();
        dis_a[u] = st;
        for (auto v : adj[u]) {
            if (dis_a[v] > dis_a[u]+1) {
                q.push({v, st+1});
            }
        } 
    }
    q.push({b, 0});
    while (q.size()) {
        auto [u, st] = q.front();
        q.pop();
        dis_b[u] = st;
        int diff = dis_b[u] - dis_a[u];
        if (diff == 0 || diff == 1) {
            vx = u, fnd = st;
            break;
        }
        for (auto v : adj[u]) {
            if (dis_b[v] > dis_b[u]+1) {
                q.push({v, st+1});
            }
        } 
    }
    int ans = fnd + 2*(n-1);
    vector<bool> vis(n);
    int stay = 0;
    while (q.size()) q.pop();
    q.push({vx, 0});
    while (q.size()) {
        auto [u, st] = q.front();
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        stay = max(stay, st);
        for (auto v : adj[u]) {
            if (!vis[v]) q.push({v, st+1});
        }
    }
    ans -= stay;
    cout << ans << '\n';
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
