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

void solve() {
    int N, M;
    cin >> N >> M;
    vvi g(N, vi(M));
    pair<int, int> st;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j) {
            char x; cin >> x;
            if (x == 'a') g[i][j] = 1;
            else if (x == 'b') g[i][j] = -1;
            else if (x == 'i') st.first = i, st.second = j;
        }
    int r = st.first, c = st.second;
    vvi prfx1(1010, vi(1010)), prfx2(1010, vi(1010)), prfx3(1010, vi(1010)), prfx4(1010, vi(1010));

    for (int i = r+1; i >= 1; --i)
        for (int j = c+1; j >= 1; --j) {
            prfx1[i][j] = prfx1[i+1][j] + prfx1[i][j+1] - prfx1[i+1][j+1] + g[i-1][j-1];
        }
    for (int i = r+1; i <= N; ++i)
        for (int j = c+1; j <= M; ++j) {
            prfx2[i][j] = prfx2[i-1][j] + prfx2[i][j-1] - prfx2[i-1][j-1] + g[i-1][j-1];
        }
    for (int i = r+1; i >= 1; --i)
        for (int j = c+1; j <= M; ++j) {
            prfx3[i][j] = prfx3[i+1][j] + prfx3[i][j-1] - prfx3[i+1][j-1] + g[i-1][j-1];
        }
    for (int i = r+1; i <= N; ++i)
        for (int j = c+1; j >= 1; --j) {
            prfx4[i][j] = prfx4[i-1][j] + prfx4[i][j+1] - prfx4[i-1][j+1] + g[i-1][j-1];
        }
    int ans = 0;
    for (auto& x : prfx1) for (auto y : x) ans = max(ans, y);
    for (auto& x : prfx2) for (auto y : x) ans = max(ans, y);
    for (auto& x : prfx3) for (auto y : x) ans = max(ans, y);
    for (auto& x : prfx4) for (auto y : x) ans = max(ans, y);
    cout << ans << '\n';
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
