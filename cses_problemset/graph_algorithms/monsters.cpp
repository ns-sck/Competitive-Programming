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

int rr[4] = {0, 1, 0, -1};
int cc[4] = {1, 0, -1, 0};
char go[4] = {'R', 'D', 'L', 'U'};

void solve() {
    int N, M;
    cin >> N >> M;

    vvi g(N, vi(M));
    pi src;
    vvi q, dis(N, vi(M, INF));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            char c; cin >> c;
            if (c == 'M') {
                q.pb({i, j, 0});
            }
            if (c == '#') g[i][j] = 1;
            if (c == 'A') src = {i, j};
        }
    }    

    int idx = 0;
    while (idx < q.size()) {
        vi vc = q[idx];
        ++idx;
        
        int i = vc[0], j = vc[1], d = vc[2];
        if (dis[i][j] <= d) continue;
        dis[i][j] = d;

        for (int k = 0; k < 4; ++k) {
            int ii = i + rr[k];
            int jj = j + cc[k];
            if (~ii && ii < N && ~jj && jj < M && !g[ii][jj]) q.pb({ii, jj, d + 1});
        }
    }

    vvi par(N, vi(M));
    vector<vector<bool>> vis(N, vector<bool>(M));

    q = {{src.first, src.second, 0}};
    idx = 0;
    pi ex = {-1, -1};
    int ans = -1;

    auto crn = [&](int i, int j) {
        return i == N - 1 || !i || j == M - 1 || !j;
    };
    
    while (idx < q.size()) {
    
        vi vc = q[idx];
        ++idx;

        int i = vc[0], j = vc[1], d = vc[2];
        if (crn(i, j)) {
            ex = {i, j};
            ans = d;
            break;
        }
        for (int k = 0; k < 4; ++k) {
            int ii = i + rr[k];
            int jj = j + cc[k];
            if (~ii && ii < N && ~jj && jj < M && !g[ii][jj] && !vis[ii][jj] && (dis[ii][jj] > d + 1 || (crn(i, j) && dis[ii][jj] == d + 1))) {
                q.pb({ii, jj, d + 1});
                par[ii][jj] = k;
                vis[ii][jj] = 1;
            }
        }
    }

    if (~ans) {
        put("YES");
        put(ans);
        int i = ex.first, j = ex.second;
        string s;
        for (;;) {
            if (i == src.first && j == src.second) break;
            s += go[par[i][j]];
            int a = i, b = j;
            i -= rr[par[a][b]];
            j -= cc[par[a][b]];
        }
        reverse(all(s));
        cout << s;
    } else {
        cout << "NO\n";
    }
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}