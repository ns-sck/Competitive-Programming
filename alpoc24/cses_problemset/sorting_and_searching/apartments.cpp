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

    int n, m, k;
    cin >> n >> m >> k;
    vi v1(n);
    vi v2(m);
    for (int i = 0; i < n; ++i) cin >> v1[i];
    for (int i = 0; i < m; ++i) cin >> v2[i];
    sort(all(v1));
    sort(all(v2));
    int j = 0, i = 0;
    int ans = 0;
    while (i < n && j < m) {
        if (v2[j] + k < v1[i]) ++j;
        else if (abs(v1[i] - v2[j]) <= k) {
            ++ans; 
            ++j; ++i;
        } 
        else ++i;
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
