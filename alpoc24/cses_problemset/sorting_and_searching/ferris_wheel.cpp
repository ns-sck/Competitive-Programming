#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pi pair<int, int>
#define vi vector<int>
#define vii vector<vector<int>>
#define vpi vector<pi>
#define pb push_back
#define ar array
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const int MOD = 1e9+7;
const int INF = 1e18;
const int _max = 2e5+1;
const long double EPS = 1e-9; 

void solve() {
    int n, x;
    cin >> n >> x;
    vi v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    int r = n-1;
    int ans = 0;
    int nm = n;
    sort(all(v));
    for (int l = 0; l < n; ++l) {
        while (r > l && v[r] + v[l] > x) --r;
        if (r > l) {
            ++ans;
            --r;
            nm -= 2;
        } else {
            ans += nm;
            cout << ans;
            return;
        }
    }   
}

int32_t main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
