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
    int N; cin >> N;
    string S; cin >> S;
    vi hs(N+1), pw(N+1), inv(N+1);
    int p = 37, x = 1;
    for (int i = 1; i <= N; ++i) {
        pw[i] = x;
        x = (x * p) % MOD;
    }
    for (int i = 1; i <= N; ++i) {
        inv[i] = fp(pw[i], MOD-2);
    }
    for (int i = 1; i <= N; ++i) {
        int c = S[i-1]-'a'+1;
        hs[i] = (hs[i-1] + c * pw[i]) % MOD;
        x = (x * p) % MOD;
    }

    auto bs = [&] (int a, int b, int c, int d) {
        int lo = 0, hi = min(b-a, d-c) + 1;
        while (lo < hi) {
            int mi = (lo + hi) >> 1;
            int h1 = (((hs[a+mi] - hs[a-1] + MOD) % MOD) * inv[a]) % MOD;
            int h2 = (((hs[c+mi] - hs[c-1] + MOD) % MOD) * inv[c]) % MOD;
            if (h1 ^ h2) {
                hi = mi;
            } else lo = mi+1;
        }

        int x1 = b-a >= lo ? S[a+lo-1]-'a' : -1;
        int x2 = d-c >= lo ? S[c+lo-1]-'a' : -1;
        return (x1 <= x2); 
    };

    int Q; cin >> Q;
    while (Q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (bs(a, b, c, d)) cout << "YES\n";
        else cout << "NO\n";
    }
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
