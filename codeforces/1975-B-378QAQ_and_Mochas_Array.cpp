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
    vi v(n);
    for (auto& x : v) cin >> x;
    sort(all(v));
    int x = v[0];
    vi v2;
    for (auto y : v) if (y%x) v2.pb(y);
    if (!v2.size()) {
        cout << "Yes\n";
        return;
    }
    sort(all(v2));
    x = v2[0];
    for (auto y : v2) {
        if (y%x) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
