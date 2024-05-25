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
const ll MAX = 1e5+1;
const ld EPS = 1e-9; 

int bs(int r, int sq) {
    int ans = 0;
    for (int i = r; i; --i) {
        int l = 0, h = r;
        int ub, d = 0;
        while (l <= h) {
            int m = (l+h)/2;
            d = m*m + i*i;
            if (d < sq) l = m+1;
            else h = m-1;
            ub = m;
        }
        if (d >= sq) --ub;
        ans += 2*(2*ub+1);
    }
    return ans;
}
void solve() {

    int q; cin >> q;
    while (q--) {
        int r; cin >> r;
        int ans = 0;
        int sq = (r+1)*(r+1), sq2 = r*r;
        int ans1 = bs(r, sq), ans2 = bs(r, sq2);
        cout << ans1-ans2 << '\n';
    }
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
