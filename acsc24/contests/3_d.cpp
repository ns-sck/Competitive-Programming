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

vvi qrs;
map<pi, int> edgs;
int sz[MAX], par[MAX];

int find(int u) {
    return u == par[u] ? u : par[u] = find(par[u]);
}
 
void uni(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return;
    if (sz[u] > sz[v]) swap(u, v);
    par[u] = v;
    sz[v] += sz[u];
}

void solve() {
    int N, M, Q;
    cin >> N >> M >> Q;
    int j = 0;
    while (M--) {
        int u, v;
        cin >> u >> v;
        if (u > v) swap(u, v);
        ++edgs[{u, v}];
    }
    for (int i = 0; i < Q; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        qrs.pb({a, b, c});
        if (a == 2) {
            if (b > c) {
                swap(b, c);
            }
            --edgs[{b, c}];
        }
    }
    for (int i = 1; i <= N; ++i) par[i] = i, sz[i] = 1;
    for (auto& pr : edgs) {
        auto [pr1, j] = pr;
        auto [u, v] = pr1;
        if (j > 0) {
            uni(u, v);
        }
    }
    vector<string> ans;
    for (int i = qrs.size()-1; ~i; --i) {
        int qt = qrs[i][0], u = qrs[i][1], v = qrs[i][2];
        if (qt == 1) {
            if (find(u) == find(v)) ans.pb("YES");
            else ans.pb("NO"); 
        } else {
            uni(u, v);
        }
    }
    reverse(all(ans));
    for (auto& s : ans) cout << s << '\n';
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
