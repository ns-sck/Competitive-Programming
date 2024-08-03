#include <bits/stdc++.h>
using namespace std;

template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...); cout << '\n';}

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
    map<int, int> mp;
    for (int i = 0; i < N; ++i) {
        int x; cin >> x;
        ++mp[x];
    }
    int ans = INF;
    for (auto& [p1, c] : mp) {
        if (ans == 0) break;
        int p2 = p1+1;
        if (mp.count(p2)) {
            int up1 = min(c, M/p1);
            int up2 = min(mp[p2], M/p2);
            for (int i = 0; i <= up1 && ans; ++i) {
                int c2 = min(up2, (M - i*p1) / p2);
                ans = min(ans, M - (i*p1 + c2*p2));
            }
        } else {
            int up1 = min(c, M/p1);
            ans = min(ans, M - (up1*p1));
        }
    }
    cout << M - ans << '\n';
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
