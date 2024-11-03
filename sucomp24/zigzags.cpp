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

vi sol_kucuk, sol_buyuk, sag_kucuk, sag_buyuk, a, b, c, d;
int N;

void upd(vi& st, int k, int x){
    k += N;
    st[k] = x; 
    k >>= 1;
    while(k >= 1){
        st[k] = max(st[2*k], st[2*k+1]);
        k >>= 1;
    }
}

void upd2(vi& st, int k, int x){
    k += N;
    st[k] = x; 
    k >>= 1;
    while(k >= 1){
        st[k] = st[2*k] + st[2*k+1];
        k >>= 1;
    }
}

ll qry(vi& st, int a, int b){
    a += N, b += N;
    int ans = 0;
    while(a <= b){
        if (a&1) ans = max(ans, st[a++]);
        if (~b&1) ans = max(ans, st[b--]);
        a >>= 1, b >>= 1;
    }
    return ans;
}

ll sum(vi& st, int a, int b){
    a += N, b += N;
    int ans = 0;
    while(a <= b){
        if (a&1) ans += st[a++];
        if (~b&1) ans += st[b--];
        a >>= 1, b >>= 1;
    }
    return ans;
}

void solve() {
    cin >> N;

    sol_buyuk.assign(2 * N, 0);
    sol_kucuk.assign(2 * N, 0);
    sag_buyuk.assign(2 * N, 0);
    sag_kucuk.assign(2 * N, 0);
    a.assign(2 * N, 0);
    b.assign(2 * N, 0);
    c.assign(2 * N, 0);
    d.assign(2 * N, 0);

    vi v(N);
    for (int& x : v) cin >> x, --x;
    int ans = 0;

    for (int i = N - 1; ~i; --i) {
        int x = v[i];
        // int q = sum(c, 0, x - 1);
        // upd2(sag_kucuk, x, q);
        // upd2(c, x, 1);

        int q = sum(d, x + 1, N - 1);
        upd2(sag_buyuk, x, q);
        upd2(d, x, 1);
    }

    for (int i = 0; i < N; ++i) {
        int x = v[i];

        // int q = sum(a, x + 1, N - 1);
        // upd2(sol_buyuk, x, q);
        // upd2(a, x, 1);

        int q = sum(b, 0, x - 1);
        upd2(sol_kucuk, x, q);
        upd2(b, x, 1);

        if (i > 1 && i < N - 1) {
            // int s = sum(sol_buyuk, 0, x - 1);
            // ans = (ans + s * sag_kucuk[x + N]) % MOD;
            int s = sum(sol_kucuk, x + 1, N - 1);
            ans = (ans + s * sag_buyuk[x + N]) % MOD;
        }
    }

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