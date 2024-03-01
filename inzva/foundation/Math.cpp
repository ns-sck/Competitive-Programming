#include<bits/stdc++.h>
#define inf INT_MAX
#define ll long long
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define fri(b) freopen(b,"r",stdin)
#define fro(b) freopen(b,"w",stdout)
#define bassifir(a) __builtin_clz(a)
#define sonsifir(a) __builtin_ctz(a)
#define birsay(a) __builtin_popcount(a)
#define UPP 3000013ll
#define MOD (ll)1e9+7ll 


using namespace std;


ll lp[UPP+1];
vector <ll> pr;

void sieve() {
	for(ll i = 2; i <= UPP; i++) {
		if(!lp[i]) {
			lp[i] = i;
			pr.pb(i);
		}
		for(int j = 0; j < pr.size() && pr[j] <= lp[i] && i * pr[j] <= UPP; j++) {
			lp[i * pr[j]] = pr[j];
		}
	}
}



long long fact[UPP];

ll fastpow (ll a, ll b) {
	ll ans = 1ll;
	while (b) {
		if (b % 2ll) {
			ans *= a;
			ans %= MOD;
		}
		b /= 2ll;
		a *= a;
		a %= MOD;
	}
	return ans;
}

long long modinverse(long long x){
	return fastpow(x,MOD-2);
}

long long comb(long long x,long long y){
	if(x<y){
		return 0;
	}
	if(y==0){
		return 1;
	}
	return (((fact[x]*modinverse(fact[y]))%MOD) * (modinverse(fact[x-y])%MOD))%MOD;
}

ll phi(ll x) {
    ll ans = x;
    for(ll i = 2ll; i * i <= x; i++) {
        if (x % i == 0) {
            while (x % i == 0) {
				x /= i;
			}
            ans -= (ans / i);
        }
    }
    if (x > 1ll) {
		ans -= ans / x;
	}
    return ans;
}