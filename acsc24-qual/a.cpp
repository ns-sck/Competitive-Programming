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
const ll MAX = 29;
const ld EPS = 1e-9; 

int par[MAX];
vi adj[MAX];
bool is[MAX];

void solve() {
    int N, M, C;
    cin >> N >> M >> C;
    vi v(N);
    for (auto& x : v) cin >> x;
    for (int i = 0; i < N; ++i) par[i] = i;
    while (C--) {
        int u, v1;
        cin >> u >> v1;
        if (v1 < u) {
            swap(v[u], v[v1]);
            par[v1] = u;
            is[v1] = 1;
        } else {
            par[u] = v1;
            is[u] = 1;
        }
    }

    int msk = (1 << N), ans = 0;
    for (int i = 0; i < msk; ++i) {
        int no = 0;
        int t = 0, c = 0;
        for (int j = 0; j < N; ++j) {
            if (i & (1 << j) && (((1 << j) & no) == 0)) {
                no |= (1 << par[j]);
                t += v[j];
                if (is[j]) t += v[par[j]];
                c += 1 + is[j];
            }
        }
        if (c <= M) ans = max(ans, t);
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
