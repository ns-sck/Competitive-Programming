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
const ll MAX = 1e3+37;

int rr[4] = {0, -1, 0, 1};
int cc[4] = {1, 0, -1, 0};

vi w, p;
vpi v;
int dp[MAX][MAX];
int g[MAX][MAX];
int N, M;
int csz = 0, one = 0, t = 0;
int gr[10];

int rec(int i, int rm) {
    if (i == w.size()) return rm > 0 ? INF : 0ll;
    if (rm < 0) return 0;
    auto& ref = dp[i][rm];
    if (~ref) return ref;
    int a = w[i] + rec(i+1, rm-p[i]);
    int b = rec(i+1, rm);
    return ref = min(a, b); 
}

void dfs(int i, int j) {
    if (i < 0 || i >= N || j < 0 || j >= M || !g[i][j]) return;
    ++csz, one += g[i][j] == 1;
    ++gr[g[i][j]];
    g[i][j] = 0;
    for (int k = 0; k < 4; ++k)
        dfs(i+rr[k], j+cc[k]);
}

void solve() {
    cin >> N >> M;
    t = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> g[i][j], t += (g[i][j] != 0);

    w.clear();
    p.clear();
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (!g[i][j]) continue;
            csz = 0;
            one = 0;
            memset(gr, 0, sizeof(gr));
            dfs(i, j);
            priority_queue<pi> pq;
            for (int k = 2; k < 10; ++k) pq.push({gr[k], k});
            int cost = 0;
            while (pq.size() && one <= pq.top().first) {
                auto [c, x] = pq.top();
                pq.pop();
                ++one; ++cost;
                pq.push({c-1, x});
            }
            w.pb(cost);
            p.pb(csz);
        }
    }
    int nd = t/2+1;
    int ans = rec(0, nd);
    cout << ans << '\n';
}

signed main () {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
