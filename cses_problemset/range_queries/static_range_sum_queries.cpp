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
const int MAX = 2e5+1;
const long double EPS = 1e-9; 

void solve() {
    int n, q;
    cin >> n >> q;
    vi v(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        v[i] += v[i-1];
    }    
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << v[b] - v[a-1] << '\n';
    }
}

int32_t main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
