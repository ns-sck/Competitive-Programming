#include <bits/stdc++.h>
using namespace std;

template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...); cout << '\n';}

#define int long long
#define ll long long
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

int par[MAX];
int sz[MAX];
int vis2[MAX];

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
    int N, M;
    cin >> N >> M;

    vvi g(N, vi(M));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            char c; cin >> c;
            if (c == '#') g[i][j] = 1;
        }
    }

    vi st(M + 1), end(M + 1);
    vector<vector<bool>> vis(N, vector<bool>(M));

    int rr[4] = {0, 1, 0, -1};
    int cc[4] = {1, 0, -1, 0};

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {

            if (vis[j][i]) continue;

            vpi q = {{j, i}};
            int idx = 0, cnt = 0, mx = 0;

            while (idx < q.size()) {
                auto [r, c] = q[idx];
                ++idx;
                if (vis[r][c]) continue;
                ++cnt;
                mx = max(mx, c);
                vis[r][c] = 1;

                for (int x = 0; x < 4; ++x) {
                    int nr = r + rr[x];
                    int nc = c + cc[x];
                    if (~nr && nr < N && ~nc && nc < M && !vis[nr][nc]) q.pb({nr, nc});
                }
            }
            st[j] += cnt;
            end[mx] += cnt;
        }
    }

    for (int i = M-1; ~i; --i) {
        st[i] += st[i+1];
    }

    for (int i = 0; i < M; ++i) {
        
    }
    
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}