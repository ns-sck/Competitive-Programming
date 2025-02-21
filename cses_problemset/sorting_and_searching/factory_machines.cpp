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
    int N, M;
    cin >> N >> M;

    vi v(N);
    for (auto& x : v) cin >> x;
    int lo = 0, hi = INF+1;
    while (lo < hi) {
        int mi = (lo+hi)>>1;
        int c = 0;
        for (int i = 0; i < N; ++i) {
            if (c > 1e9) break;
            c += mi/v[i];
        }
        if (c < M) lo = mi+1;
        else hi = mi;
    }
    cout << lo << '\n';
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
