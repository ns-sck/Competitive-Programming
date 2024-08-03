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
    --N;
    if (~N) {
        cout << 0 << '\n';
        return;
    }
    int ans = 1;
    int x = 3;
    while (x <= N) {
        if (2*x <= N) {
            N -= 2*x;
            ans += 2;
        } else {
            N -= x;
            ++ans;
        }
        x *= 3;
    }
    while (N >= 0) {
        while (N >= x) N -= x, ++ans;
        x /= 3;
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
