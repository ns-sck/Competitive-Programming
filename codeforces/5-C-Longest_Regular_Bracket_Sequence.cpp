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
const ll MAX = 1e6+10;
const long double EPS = 1e-9; 

int dp[MAX], lst[MAX];
void solve() {
    // l l r r l l r r
    string s; cin >> s;
    memset(dp, -1, sizeof(dp));
    lst[0] = 0;
    int cnt = 0, ans1 = 0, ans2 = 0, inv = 0;
    for (int i = 1; i <= s.size(); ++i) {
        if (cnt == 0 && s[i-1] == ')') continue;
        lst[cnt] = i-1;
        if (s[i-1] == '(') ++cnt;
        else {
            --cnt;
            dp[i] = ~dp[lst[cnt]] ? dp[lst[cnt]] : lst[cnt];
            ans1 = max(ans1, i-dp[i]);
        }
    }
    if (ans1 == 0) cout << 0 << ' ' << 1;
    else {
        for (int i = 0; i <= s.size(); ++i) {
            if (~dp[i] && i-dp[i] == ans1) ++ans2;
        }
        cout << ans1 << ' ' << ans2;
    }
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
