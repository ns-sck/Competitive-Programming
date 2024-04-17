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
    int n, m;
    cin >> n >> m;
    set<ar<int, 2>> s1;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        s1.insert({x,i});
    }
    for (int i = 0; i < m; ++i) {
        int x; cin >> x;
        if (s1.empty()) {
            cout << -1;
            continue;
        }
        auto it = s1.lower_bound({x+1,0});
        if (it == s1.begin()) {
            cout << -1 << '\n';
            continue;
        }
        --it;
        cout << (*it)[0] << '\n';
        s1.erase(it);
    }
}

int32_t main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
