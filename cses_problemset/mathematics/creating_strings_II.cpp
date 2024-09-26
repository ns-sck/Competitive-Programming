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

const ll MOD = 1e9+7;
const ll INF = 1e18;
const ll MAX = 1e6+1;

int fact[MAX];

void f() {
    fact[0] = 1;

    for (int i = 1; i < MAX; ++i) {
        fact[i] = (fact[i-1] * i) % MOD;
    }
}

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

int inv(int x) {
    return fp(x, MOD - 2);
}

void solve() {

    string S; cin >> S;
    f();
    vi a(26);
    int N = S.size();

    for (int i = 0; i < S.size(); ++i) {
        ++a[S[i]-'a'];
    }

    int ans = fact[N];

    for (int i = 0; i < 26; ++i) {
        ans = (ans * inv(fact[a[i]])) % MOD;
    }

    cout << ans << '\n';
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