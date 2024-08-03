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
const ll MAX = 1e3+1;

bool dp[MAX][MAX];
void solve() {
    int N; cin >> N;
    string S; cin >> S;
    for (int i = 0; i < N; ++i)
        for (int j = i; ~j; --j) {
            if (i == j) dp[j][i] = 1;
            else if (i == j+1) dp[j][i] = S[i] == S[j];
            else dp[j][i] = dp[j+1][i-1] && (S[i] == S[j]);
        }
    int ans = 0;
    for (int i = 0; i < N; ++i)
        for (int j = i-1; ~j; --j)
            ans += dp[j][i];
    cout << ans << '\n';
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
