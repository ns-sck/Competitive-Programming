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
    int n; cin >> n;
    map<int, int> mp;
    while (n--) {
        int a, b;
        cin >> a >> b;
        mp[b] = max(mp[b], a);
    }
    int last = 0, ans = 0;
    for (auto x : mp) {
        if (x.second >= last) {
            ++ans;
            last = x.first;
        }
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
