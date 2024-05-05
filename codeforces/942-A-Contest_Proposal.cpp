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

void solve() {
    int ans = 0;
    int n; cin >> n;
    vi v(n), v2(n);
    for (auto& x : v) cin >> x;
    for (auto& x : v2) cin >> x;
    for (int i = 0; i < n-ans; ++i) {
        int j = i+ans;
        while (j < n && v2[j] < v[i]) {
            ++ans; ++j;
        }
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
