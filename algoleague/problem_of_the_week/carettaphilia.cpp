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

ll lp[MAX+1], fct[MAX];
vector<ll> pr;

void sieve() {
	for(ll i = 2; i <= MAX; i++) {
		if(!lp[i]) {
			lp[i] = i;
			pr.push_back(i);
		}
		for(int j = 0; j < pr.size() && pr[j] <= lp[i] && i * pr[j] <= MAX; j++) {
			lp[i * pr[j]] = pr[j];
		}
	}
}

int fp(int base, int exp) {
    int ans = 1;
    for(int i = 0; i < 45; i++) {
        if((1LL << i) & exp)
            ans *= base;
        base *= base;
        base %= MOD;
        ans %= MOD;
    }
    return ans;
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
	if(x < y){
		return 0;
	}
	if(y == 0){
		return 1;
	}
	return (((fct[x] * inv(fct[y])) % MOD) * (inv(fct[x-y]) % MOD)) % MOD;
}

void solve() {
	int N, M;
    cin >> N >> M;
    int ans = 0;
    f();
    sieve();
    for (auto p : pr) {
        if (p == 2) continue;
        if (p > M) break;
        int x = p;
        while (x <= M) {
            ans = (ans + comb(M, x)) % MOD;
            x *= p;
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
