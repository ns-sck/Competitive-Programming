#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define pi pair<int, int>
#define vi vector<int>
#define vii vector<vector<int>>
#define vpi vector<pi>
#define pb push_back
#define ar array
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const ll MOD = 1e9+7;
const ll INF = 1e18;
const ll MAX = 2e5+1;
const long double EPS = 1e-9; 

int p[MAX];
unordered_map<int, int> idx, dp;
void solve() {
    int n; cin >> n;
    int j = 0;
    vi arr(MAX), v;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        dp[arr[i]] = dp[arr[i]-1]+1;
        if (dp[arr[i]] > dp[arr[j]]) j = i;
        idx[arr[i]] = i;
        p[i] = idx[arr[i]-1];
    }
    cout << dp[arr[j]] << '\n';
    v.pb(j);
    while (p[j]) {
        v.pb(p[j]);
        j = p[j];
    }
    reverse(all(v));
    for (auto x : v) cout << x << ' ';
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
