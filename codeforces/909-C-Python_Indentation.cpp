#include <bits/stdc++.h>
using namespace std;

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
const ll MAX = 5e3+2;
const long double EPS = 1e-9; 
int dp[MAX][MAX];

void solve() {
    int n; cin >> n;
    dp[0][0] = 1;
    char lst; cin >> lst;
    for (int i = 1; i < n; ++i) {
        char c; cin >> c;
        for (int j = i; ~j; --j) {
            if (lst == 'f') {
                if (j) dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
            } else {
                dp[i][j] = max(dp[i][j], dp[i][j+1]);
                dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
            }
        }
        lst = c;
    }
    int ans = 0;
    if (lst == 's')
        for(auto x : dp[n-1]) ans = (ans + x) % MOD;
    cout << ans;
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
