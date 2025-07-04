#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e7 + 5;
const int P = 1e7 + 5;
const int mod = 1e9 + 7;

ll exp(ll a, ll b) {
    ll r = 1;
    while (b) {
        if (b & 1)
            (r *= a) %= mod;
        b >>= 1;
        (a *= a) %= mod;
    }
    return r;
}
ll inv(ll a) { return exp(a, mod - 2); }

int main(int argc, char **argv) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> lpf(P);
    vector<bool> square_free(P, 1);
    for (int i = 2; i < P; i++) {
        if (lpf[i])
            continue;
        for (int k = i; k < P; k += i)
            lpf[k] = i;
        for(ll k = (ll)i*i; k < P; k += (ll)i*i) square_free[k] = 0;
    }

    vector<ll> pre(1, 1);
    ll f = 1;
    for (int i = 1; i < N; i++)
        pre.push_back((pre.back() * ((f *= i) %= mod)) % mod);

    auto get_trailing_zeros_up_to = [&](int x, int k) {
        int p = lpf[k];
        ll pw = p;
        int exp = 1;
        ll cnt = 0;
        for (; pw <= x; pw *= p, exp++) {
            ll m = x / pw - 1;
            // 1 1 1 ... 2 2 2 ... m m m
            // each pw times
            cnt += m * (m + 1) / 2 * pw;
            cnt += (m + 1) * (x - (m + 1) * pw + 1);
        }
        return cnt;
    };

    int q;
    cin >> q;
    assert(1 <= q && q <= 5e5);
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        
        assert(1 <= l && l <= r && r <= 1e7);
        assert(2 <= k && k <= 1e7);
        assert(square_free[k]);

        ll ans = pre[r] * inv(exp(k, get_trailing_zeros_up_to(r, k))) % mod;
        ll div = pre[l - 1] * inv(exp(k, get_trailing_zeros_up_to(l - 1, k))) % mod;
        (ans *= inv(div)) %= mod;
        cout << ans;
        if (q)
            cout << "\n";
    }
}