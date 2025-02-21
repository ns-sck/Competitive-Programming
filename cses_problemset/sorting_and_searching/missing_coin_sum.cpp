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
    vi v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    sort(all(v));
    int total = 0;
    for (int i = 0; i < n; ++i) {
        if (v[i] > total+1) {
            cout << total+1;
            return;
        }
        total += v[i];
    }
    cout << total+1;
}

int32_t main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
