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

int x[4] = {-1,0,1,0};
int y[4] = {0,-1,0,1};

void solve() {
    int N, M;
    cin >> N >> M;
    int g[N][M];
    set<pi> s;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j) {
            cin >> g[i][j];
        }

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j) {
            int m = 0;
            for (int k = 0; k < 4; ++k) {
                int ii = i+y[k];
                int jj = j+x[k];
                if (~ii && ~jj && ii < N && jj < M) m = max(m, g[ii][jj]);
            }
            if (g[i][j] > m) s.insert({i, j});
        }

    while (s.size()) {
        auto [i, j] = *s.begin();
        int m = 0;
        for (int k = 0; k < 4; ++k) {
            int ii = i+y[k];
            int jj = j+x[k];
            if (~ii && ~jj && ii < N && jj < M) m = max(m, g[ii][jj]);
        }
        if (m < g[i][j]) g[i][j] = m;
        s.erase(s.begin());
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << g[i][j] << ' ';
        }
        cout << '\n';
    }
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
