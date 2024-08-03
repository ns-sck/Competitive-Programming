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

int fp(int base, int exp) {
    int rval = 1LL;
    while (exp) {
        if (exp & 1) {
            rval *= base;
            rval %= MOD;
        }
        base *= base;
        base %= MOD;
        exp >>= 1;
    }
    return rval;
}

void solve() {
    string S, s;
    cin >> S >> s;
    int x = 0, y = 31;
    vi pw(MAX);
    pw[0] = 1;
    for (int i = 1; i < MAX; ++i) {
        pw[i] = (pw[i-1]*31) % MOD;
    }
    for (auto& c : s) {
        int a = c-'a'+1;
        x = (x + y*a) % MOD;
        y = (y*31) % MOD;
    }
    vi h(S.size()+1);
    int ans = 0;
    for (int i = 1; i <= S.size(); ++i) {
        int a = S[i-1]-'a'+1;
        h[i] = (h[i-1] + a*pw[i]);
    }
    for (int i = s.size(); i <= S.size(); ++i) {
        int j = i - s.size();
        int z = ((h[i] - h[j] + MOD) % MOD) * fp(pw[j], MOD-2);
        z %= MOD;
        if (z == x) ++ans;
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
