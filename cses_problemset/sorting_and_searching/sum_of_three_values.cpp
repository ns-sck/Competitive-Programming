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
    for (int& x : v) cin >> x;
    sort(all(v));
    for (int i = 0; i < N; ++i) {
        int j = 0, k = N-1;
        while (j < k) {
            int t = v[j]+v[k];
            if (j == i || k == i) {
                t+v[i] > M ? --k : ++j;
                continue;
            }
            if (t > M-v[i]) --k;
            else if (t < M-v[i]) ++j;
            else {
                cout << i+1 << ' ' << j+1 << ' ' << k+1 << '\n';
                return;
            }
        }
    }
    cout << "IMPOSSIBLE";
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
