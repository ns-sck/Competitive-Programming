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
const ll MAX = 5e3+1;
const long double EPS = 1e-9; 

int dp[MAX][MAX];
bool b[MAX][MAX];
void solve() {
    string s; cin >> s;
    int q; cin >> q;
    int sz = s.size();
    for (int i = 0; i <= sz; ++i)
        for (int j = i; ~j; --j) {
            if (i == j) {
                dp[i][j] = 1;
                b[i][j] = 1;
            }
            else {
                if (j == i-1) b[i][j] = s[i] == s[j];
                else b[i][j] = b[i-1][j+1] && s[i] == s[j];
                dp[i][j] = dp[i][j+1] + dp[i-1][j] - dp[i-1][j+1] + (s[i] == s[j] && b[i][j]);
            }
        }
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << dp[r-1][l-1] << '\n';
    }
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
