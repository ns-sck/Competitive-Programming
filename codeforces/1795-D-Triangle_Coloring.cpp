#include <bits/stdc++.h>
using namespace std;

template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...); cout << '\n';}

#define int long long
#define ll long long
#define pi pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpi vector<pi>
#define pb push_back
#define ar array
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const ll MOD = 998244353;
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

void solve() {
    int N; cin >> N;
    int x = N / 3;

    f();

    int ans = 1;
    for (int i = 0; i < x; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a > b) swap(a, b);
        if (b > c) swap(b, c);
        if (a > b) swap(a, b);
        assert(a <= b <= c);
        if (a == b && b == c) ans = (ans * 3) % MOD;
        else if (a == b) ans = (ans * 2) % MOD;
    }

    ans = (ans * comb(x, x >> 1)) % MOD;
    put(ans);
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}