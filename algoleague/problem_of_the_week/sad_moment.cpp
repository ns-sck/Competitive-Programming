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

ll fct[MAX];
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
long long inv(long long x){
	return fp(x, MOD-2);
}

void f() {
    fct[1] = fct[0] = 1;
    for (int i = 2; i < MAX; ++i) {
        fct[i] = (fct[i-1] * i) % MOD;
    }
}

long long comb(long long x, long long y){
	if(x < y) return 0;
	if(y == 0) return 1;
	return (((fct[x] * inv(fct[y])) % MOD) * (inv(fct[x-y]) % MOD)) % MOD;
}
// _ _ _ H _ _ H _ _  --> 1 + 2 + 3 + 2

// _ _ _ _ H _ _ _ H _ _ _   15
// _ _ _ _ H S S _ H _ S S   9/3/3 = 1;  
// _ _ _ _ H S _ _ H S S S     
// 3-1 = 2
// 2-2 = 1

// _ S _ S _ S _
// HSSSHSSS
// _______________
// HSSS_____HSSS__
// _HSSS
// __HSSS
// ___HSSS

// HSSHS, HSHSS, SHHSS, SHSHS, SHSSH, SSHHS, SSHSH, SSSHH
void solve() {
    int S, H, R;
    cin >> S >> H >> R;
    f();
    vi ans(S+1);
    int b = 0, t = 0;
    for (int i = 0; i <= H; ++i) {
        t += R + (i == 0);
        if (t < S) continue;
        for (int j = 1; j <= t; ++j) {
            ans[j] = (ans[j] + )
        }
        b = t;
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
