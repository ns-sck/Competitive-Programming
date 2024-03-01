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
constexpr ll mod = ll(1e9) + 7;
constexpr ll factor = 31;


ll t=1, cases = 0, n, q;
map<pair<int, int>, ll> precomp;
vector<ll> hashes;


void hashcalc(string &s, int strind) {
    ll cur = 0;

    for(int i = 0; i < sz(s); i++) {
        cur *= factor;
        cur += s[i] - 'a' + 1;

        precomp[{strind, i}] = cur;
        hashes.pb(cur);
    }
}


int query(int strind, int ind) {
    ll cur = precomp[{strind, ind}];

    return upper_bound(hashes.begin(), hashes.end(), cur) - lower_bound(hashes.begin(), hashes.end(), cur);
}


void solve(){
    cin >> n >> q;

    vector<string> s(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> s[i];
        hashcalc(s[i], i);
    }

    sort(hashes.begin(), hashes.end());

    while(q--) {
        int a, b;
        cin >> a >> b;

        cout << query(a, b - 1) << bl;
    }
} 


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    //cin>>t;
    for(; cases < t; cases++)solve();

    return 0;
}