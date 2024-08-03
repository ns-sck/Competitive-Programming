#include <bits/stdc++.h>
using namespace std;

template<typename... T>
void dbg(T&&... args) { ((cout << args << " "), ...); cout << '\n';}

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

ll fct[64];
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
    for (int i = 2; i < 64; ++i) {
        fct[i] = (fct[i-1] * i) % MOD;
    }
}

long long comb(long long x, long long y){
	if(x < y) return 0;
	if(y == 0) return 1;
	return (((fct[x] * inv(fct[y])) % MOD) * (inv(fct[x-y]) % MOD)) % MOD;
}

void solve() {
    int N; cin >> N;
    ll ans = 0;
    int x = N/2 + (N%2), y = N-x;
    f();
    for (int i = 1; i <= N; ++i) {
        for (int o = 1; o <= i; o += 2) {
            ans += comb(x, o)*comb(y, i-o);
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
