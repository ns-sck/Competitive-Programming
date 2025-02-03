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
    int N, Q;
    cin >> N >> Q;
    set<int> s;
    s.insert(0);
    s.insert(N);
    vi v, av;
    for (int i = 0; i < Q; ++i) {
        int x; cin >> x;
        s.insert(x);
        v.pb(x);
    }
    int ans = 0, l = 0;
    for (auto& x : s) {
        ans = max(ans, x-l);
        l = x;
    }
    while (v.size()) {
        av.pb(ans);
        int i = v[v.size()-1];
        auto lp = s.find(i), rp = lp;
        --lp, ++rp;
        ans = max(ans, *rp-*lp);
        s.erase(i);
        v.pop_back();
    }
    for (int i = Q-1; ~i; --i) cout << av[i] << ' ';
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
