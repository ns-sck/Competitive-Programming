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
map<int, int> p;
map<int, int> up, down;

void solve() {
    int N; cin >> N;

    for (int i = 0; i < N; ++i) {
        int s, r, l;
        cin >> s >> r >> l;
        p[s] = 0, p[s-1], p[s+1];
        p[s+l] = 0, p[s+l-1], p[s+l+1];
        p[s+2*l+1] = 0;
        up[s] += r, down[s+l] += -2*r, down[s+2*l+1] += r;
    }
    int prv = p.begin()->first-1, c = 0;
    for (auto& pr : p) {
        int idx = pr.first, val = pr.second;
        c += up[idx];
        p[idx] = p[prv] + c * (idx-prv);
        c += down[idx]; 
        prv = idx;
    }
    int ans = 0;
    for (auto& x : p) ans = max(ans, x.second);
    cout << ans << '\n';
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}

// 1   2   3    4    5    6     7     8     9    10
// 5   10  15   10   5
//         7    14   7
//              8    16  24     32    24    16    8
//     9   18   27   36   45    36    27    18    9    
// 8   16   24  32   24   16     8    
