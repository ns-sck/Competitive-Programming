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
const ll MAX = 100+1;
const ld EPS = 1e-9; 

string S;
vvi dp(MAX, vi(4, -1));

int dfs(int j, bool tg, int l) {
    if (j == S.size()) return 1;
    if (!tg) return dp[j][l];
    int ans = 0;
    if (!tg)
        for (int k = 0; k <= 3; ++k) {
            if (k == l) continue;
            bool ntg = ntg && (k == l);
            ans += dfs(j+1, ntg, k);
        }
    else {
        for (int k = 0; k <= S[j]-'0'; ++k) {
            
        }
    }
    return dp[j][l] = ans;
}

void solve() {
    string A, B;
    cin >> A >> B;
    S = A;
    S = B;
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
