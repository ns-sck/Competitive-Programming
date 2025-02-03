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
const ll MAX = 5e3+5;
const ld EPS = 1e-9; 

int dp[MAX][MAX][2];
int prfx[MAX+1];
void solve() {
    int N; cin >> N;
    vi v(N);
    for (auto& x : v) cin >> x;
    // 0 = a, 1 = b;
    for (int i = 1; i <= N; ++i) {
        prfx[i] += prfx[i-1] + v[i-1]; 
    }
    for (int i = 0; i < N; ++i)
        for (int j = i; ~j; --j) {
            if (i == j) {
                if (N&1) dp[j][i][0] = v[i];
                else dp[j][i][1] = v[i];
            }
            else {
                if ((N&1) != ((i-j)&1)) {
                    dp[j][i][0] = max(prfx[i]-prfx[j]-dp[j][i-1][1]+v[i], prfx[i+1]-prfx[j+1]-dp[j+1][i][1]+v[j]);
                    dp[j][i][1] = prfx[i+1]-prfx[j]-dp[j][i][0];
                }
                else {
                    dp[j][i][1] = max(prfx[i]-prfx[j]-dp[j][i-1][0]+v[i], prfx[i+1]-prfx[j+1]-dp[j+1][i][0]+v[j]);
                    dp[j][i][0] = prfx[i+1]-prfx[j]-dp[j][i][1];
                }
            }
        }
    cout << (dp[0][N-1][0]);
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
