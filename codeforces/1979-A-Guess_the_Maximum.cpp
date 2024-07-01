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

void solve() {
    int n; cin >> n;
    vi v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    int mn = -INF;
    int ans = INF;
    for (int i = 1; i < n; ++i) {
        mn = max(v[i], v[i-1]);
        ans = min(mn, ans);
    }
    cout << ans-1 << '\n';
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
