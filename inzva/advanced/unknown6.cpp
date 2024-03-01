#include <bits/stdc++.h>


#pragma GCC optimize("O3")
#pragma GCC target("sse4")


#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lsb(i) i&(-i)
#define sz(i) (int)i.size()
#define PI 3.14159265
#define bl '\n'
 

typedef long long ll;
using namespace std;
const ll INF = 1e18L;
constexpr ll mod = 1234567891;
constexpr ll mod2 = 1e9 + 7;


ll t=1, cases = 0, n, k;


ll fastpow(ll base, ll exp, ll mod) {
    ll ans = 1;
    for(int i = 0; i < 45; i++) {
        if((1LL << i) & exp)
            ans *= base;

        base *= base;
        base %= mod;
        ans %= mod;
    }
    return ans;
}


void solve(){
    cin >> n >> k;

    string s; cin >> s;

    map<ll, int> m1, m2;

    vector<ll> ar1(n + 2), ar2(n + 2);

    for(int i = 1; i <= n; i++) {
        ll cur = s[i - 1] - 'a' + 1;

        ar1[i] = ar1[i - 1] + cur * fastpow(31, n - i, mod);
        ar1[i] %= mod;

        ar2[i] = ar2[i - 1] + cur * fastpow(39, n - i, mod2);
        ar2[i] %= mod2;
    }

    ll ans = 0;
    while(k--) {
        int l, r; cin >> l >> r;

        ll hash1 = ar1[r] - ar1[l - 1];
        hash1 += mod;
        hash1 %= mod;

        hash1 *= fastpow(31, l - 1, mod);
        hash1 %= mod;

        ll hash2 = ar2[r] - ar2[l - 1];
        hash2 += mod2;
        hash2 %= mod2;

        hash2 *= fastpow(39, l - 1, mod2);
        hash2 %= mod2;

        ans += min(m1[hash1], m2[hash2]);
        m1[hash1]++;
        m2[hash2]++;
    }

    cout << ans;
} 


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    //cin>>t;
    for(; cases < t; cases++)solve();

    return 0;
}