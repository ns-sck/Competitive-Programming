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

    set<int> s1;
    int n; cin >> n;
    while (n--) {
        int x; cin >> x;
        s1.insert(x);
    }
    cout << s1.size();
}

int32_t main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
