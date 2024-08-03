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

void solve() {
	int X, Y, Q;
    cin >> X >> Y >> Q;
    vi ans;
    vpi qry;
    multiset<int> sw = {0, X}, sh = {0, Y};
    while (Q--) {
        char c; cin >> c;
        int x; cin >> x;
        if (c == 'w') sw.insert(x);
        else sh.insert(x);
        qry.pb({c == 'w', x});
    }
    int mxW = 0, mxH = 0;
    int last = *sw.begin();
    for (int x : sw) mxW = max(mxW, x-last), last = x;
    last = *sh.begin();
    for (int x : sh) mxH = max(mxH, x-last), last = x;
    for (int i = qry.size()-1; ~i; --i) {
        auto [ty, x] = qry[i];
        ans.pb(mxW*mxH);
        if (ty == 1) {
            auto it = sw.find(x);
            int nxt = *next(it), prv = *prev(it);
            sw.erase(it);
            mxW = max(mxW, (nxt-prv));
        } else {
            auto it = sh.find(x);
            int nxt = *next(it), prv = *prev(it);
            sh.erase(it);
            mxH = max(mxH, (nxt-prv));
        }
    }
    for (int i = ans.size()-1; ~i; --i) cout << ans[i] << '\n';
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
