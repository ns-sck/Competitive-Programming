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

int f(vector<int>& v) {
    vector<int> lis;
    
    for (auto x : v) {
        auto it = upper_bound(lis.begin(), lis.end(), x);
        if (it == lis.end()) lis.push_back(x);
        else *it = x;
    }
    return lis.size();
}

void solve() {
    int N; cin >> N;
    vpi v;
    int nn = N;
    while (nn--) {
        int x, y;
        cin >> x >> y;
        v.pb({x, y});
    }
    sort(all(v));
    vi v2;
    for (auto p : v) v2.pb(p.second);
    cout << f(v2);
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
