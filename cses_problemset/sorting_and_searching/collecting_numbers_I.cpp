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

const int _mod = 1e9+7;
const int _inf = 1e18;
const int _max = 2e5+1;
const long double _eps = 1e-9; 


void solve() {
    vi pos(_max);
    int n; cin >> n;
    int ans = 1;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        pos[x] = i;
    }
    for (int i = 2; i <= n; ++i) {
        if (pos[i] < pos[i-1]) ++ans;
    }
    cout << ans;
}

int32_t main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
