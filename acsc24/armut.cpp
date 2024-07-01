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
int N, a, b;

bool f(int msk, int s) {
    for (int i = 1; i < s-1; ++i) {
        if ((1<<i)&msk && ((1<<(i+1))&msk || (1<<(i-1))&msk)) return 0;
    }
    if (s == 2 && (1&msk) && 2&msk) return 0;
    return 1;
}
int g(int msk, int s) {
    int z = 1<<(s-1);
    int k = (z&msk) > 0;
    return (1&msk) + k*2;
}
void solve() {
    int N; cin >> N;
    a = N>>1, b = N-a;
    vi v1(a), v2(b);
    vector<set<int>> s1(4), s2(4);
    for (auto& x : v1) cin >> x;
    for (auto& x : v2) cin >> x;

    for (int i = 0; i < (1<<a); ++i) {
        if (!f(i, a)) continue;
        int gr = g(i, a), t = 0;
        for (int j = 0; j < a; ++j) {
            if ((1<<j)&i) t = (t + v1[j]) % MOD;
        }
        s1[gr].insert(t);
    }
    for (int i = 0; i < (1<<b); ++i) {
        if (!f(i, b)) continue;
        int gr = g(i, b), t = 0;
        for (int j = 0; j < b; ++j) {
            if ((1<<j)&i) t = (t + v2[j]) % MOD;
        }
        s2[gr].insert(t);
    }
    int ans = 0;
    vvi match = {{0,1,2,3}, {0,1}, {0,2}, {0}};
    for (int gr = 0; gr < 4; ++gr) {
        for (auto gr2 : match[gr]) {
            for (auto& x : s1[gr]) {
                auto it = s2[gr2].lower_bound(MOD-x);
                if (it != s2[gr2].begin()) {
                    --it;
                    ans = max(ans, x + *it);
                }
            }
        }
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
