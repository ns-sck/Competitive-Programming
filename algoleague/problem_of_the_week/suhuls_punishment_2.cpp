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

void solve() {
    int N, M;
    cin >> N >> M;
    vi v(MAX);
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        int x; cin >> x;
        if (M == 0) {
            if (x == 0) ans += i;
            else ans += v[0];
        } else {
            if (x != 0 && M % x == 0) ans += v[M/x];
        }
        ++v[x];
    }
    cout << ans << '\n';
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
