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
    int n, x, q;
    cin >> n >> x >> q;
    vector<ld> v1(x), v2(x);
    for (auto& y : v1) cin >> y;
    for (auto& y : v2) cin >> y;
    vector<ld> sp(x);
    sp[0] = (v1[0] / v2[0]);
    for (int i = 1; i < x; ++i) {
        sp[i] = (v1[i] - v1[i-1]) / (v2[i] - v2[i-1]);
    }
    while (q--) {
        int y; cin >> y;
        if (y == n) {
            cout << v2[x-1] << ' ';
            continue;
        }
        auto it = upper_bound(all(v1), y);
        if (it == v1.begin()) {
            cout << (int) (y / sp[0]) << ' ';
            continue;
        }
        int ans = 0, idx = it-v1.begin()-1;
        ans = v2[idx] + (y-v1[idx])/sp[idx+1];
        cout << (int) ans << ' ';
    }
    cout << '\n';
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
