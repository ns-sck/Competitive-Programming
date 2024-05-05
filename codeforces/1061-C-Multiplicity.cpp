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
const ll MAX = 2e6;
const long double EPS = 1e-9; 

ll lp[MAX+1];
vector<ll> pr;

void sieve() {
	for(ll i = 2; i <= MAX; i++) {
		if(!lp[i]) {
			lp[i] = i;
			pr.push_back(i);
		}
		for(int j = 0; j < pr.size() && pr[j] <= lp[i] && i * pr[j] <= MAX; j++) {
			lp[i * pr[j]] = pr[j];
		}
	}
}
int dp[MAX];

void solve() {
    int n; cin >> n;
    sieve();
    int ans = 0, mxE = 1;
    dp[0] = 1;
    while (n--) {
        int x; cin >> x;
        for (int i = min(mxE, (ll) (sqrt(x))); i; --i) {
            if (x % i == 0) {
                if (i*i == x) dp[i] = (dp[i] + dp[i-1]) % MOD;
                else {
                    int y = x/i;
                    dp[y] = (dp[y] + dp[y-1]) % MOD;
                    dp[i] = (dp[i] + dp[i-1]) % MOD;
                }
            }
        }
        ++mxE;
    }
    for (auto x : dp) ans = (ans + x) % MOD;
    if (ans == 0) cout << MOD-1;
    else cout << ans-1;
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
