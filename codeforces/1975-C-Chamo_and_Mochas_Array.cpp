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
    int n; cin >> n;
    if (n == 2) {
        int x, y; cin >> x >> y;
        cout << min(x, y) << '\n';
        return;
    }
    vi v(n), v2(3);
    for (auto& x : v) cin >> x;
    int ans = 0;    
    for (int i = 0; i < n-2; ++i) {
        v2 = {v[i], v[i+1], v[i+2]};
        sort(all(v2));
        ans = max(ans, v2[1]);
    }
    cout << ans << '\n';
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
