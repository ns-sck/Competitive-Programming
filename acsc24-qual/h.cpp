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
const ll MAX = 1e7+2;
const ld EPS = 1e-9; 

int P;
vi sieve() {
    vector<bool> prime(MAX, true);
    prime[0] = prime[1] = false;
    for (int p = 2; p*p < MAX; ++p) {
        if (prime[p]) {
            for (int i = p*p; i < MAX; i += p) {
                prime[i] = false;
            }
        }
    }
    vi pr;
    for (int i = 2; i < MAX; ++i) {
        if (prime[i]) {
            pr.pb(i);
        }
    }
    return pr;
}

ll fp(ll base, ll exp) {
    ll rval = 1;
    while (exp) {
        if (exp & 1) {
            rval = (rval * base) % P;
        }
        base = (base * base) % P;
        exp >>= 1;
    }
    return rval % P;
}

void solve() {
    int N, A, L;
    cin >> N >> P >> A >> L;
    assert(N <= MAX);
    vi pr = sieve();
    vi mp(12), dv(N+1);
    vector<bool> sq(N+1);
    for (auto& x : pr) {
        if (x > N) break;
        ++dv[x];
        for (ll i = 2 * x; i <= N; i += x) {
            if (i % (x*x) == 0) sq[i] = 1;
            else ++dv[i];
        }
    }
    
    for (int i = 2; i <= N; ++i) {
        if (!sq[i]) ++mp[dv[i]];
    }

    int t = 1;
    for (int i = 1; i <= 11; ++i) {
        if (!mp[i]) continue;
        int c = mp[i], dst = i;
        if (dst % 2) {
            int x = fp(A, dst-1);
            x = (x * (-A));
            x %= P;
            if (x < -P/2) x += P;
            t += c * x; 
        } else {
            int x = fp(A, dst);
            x %= P;
            if (x > P / 2) x -= P;
            t += c * x;
        }
    }
    
    if (t <= L) cout << "Lee will kill them all!";
    else cout << "Lee needs a better plan!";
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}