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
    int N, K;
    cin >> N >> K;
    vi v(N);
    map<int, vi> mp;
    for (int& x : v) cin >> x, mp[x%K].pb(x);
    int c = 0;
    for (auto& p : mp) {
        if (p.second.size()%2) ++c;
        sort(all(p.second));
    }
    if (c > 1 || (c == 1 && N%2 == 0)) {
        cout << -1 << '\n';
        return;
    }
    int ans = 0;
    for (const pair<int, vi>& p : mp) {
        int sz = p.second.size();
        vi b, r;
        if (sz%2) {
            int sz2 = sz>>1;
            b.resize(sz2+1), r.resize(sz2+1);
            for (int i = 0; i < sz; i += 2) {
                int j = i>>1;
                b[j+1] = b[j] + (p.second[i+1]-p.second[i]); 
            }
            int j = sz2;
            for (int i = sz-1; i >= 0; i -= 2) {
                r[sz2-j+1] = r[sz2-j] + (p.second[i]-p.second[i-1]);
                --j;
            }
            ll t = min(b[sz2], r[sz2]);
            for (int i = 1; i < sz-1; ++i) {
                int nb = i>>1;
                int nr = sz2-nb-(i%2);
                int d = i%2 ? (p.second[i+1]-p.second[i-1]) : 0;
                t = min(t, b[nb]+r[nr]+d);
            }
            ans += t;
        }
        else {
            for (int i = 0; i < p.second.size(); i += 2) {
                ans += (p.second[i+1]-p.second[i]);
            }
        }
    }
    cout << ans/K << '\n';
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
