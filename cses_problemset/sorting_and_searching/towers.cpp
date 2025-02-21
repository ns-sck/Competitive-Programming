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
    int N; cin >> N;
    multiset<int> s;
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        int x; cin >> x;
        auto it = s.upper_bound(x);
        if (it == s.end()) {
            s.insert(x);
            ++ans;
        } else {
            s.erase(it);
            s.insert(x);
        }
    }
    cout << ans;
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
