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

#define lch 2*i
#define rch 2*i+1

int M;

struct node {
    ll lazy, sum;
} st[60000];

void push(ll i, ll n_l, ll n_r) 
{
    st[i].sum += st[i].lazy;
    if (n_l ^ n_r) {
        st[lch].lazy += st[i].lazy;
        st[rch].lazy += st[i].lazy;
    }
    st[i].lazy = 0;
}

void upd(ll i, ll q_l, ll q_r, ll val, ll n_l = 0, ll n_r = 12000) 
{
    push(i, n_l, n_r);
    if (n_l > q_r || n_r < q_l) return;

    if (n_l >= q_l && n_r <= q_r) {
        st[i].lazy += val;
        push(i, n_l, n_r);
        return;
    }

    int mid = (n_l + n_r) / 2;
    upd(lch, q_l, q_r, val, n_l, mid);
    upd(rch, q_l, q_r, val, mid+1, n_r);

    st[i].sum = st[lch].sum + st[rch].sum;
}

ll query(ll i, ll q_l, ll q_r, ll n_l = 0, ll n_r = 12000) 
{
    push(i, n_l, n_r);
    if (n_l > q_r || n_r < q_l) return 0;
    if (n_l >= q_l && n_r <= q_r) return st[i].sum;

    int mid = (n_l + n_r) / 2;
    ll t1 = query(lch, q_l, q_r, n_l, mid);
    ll t2 = query(rch, q_l, q_r, mid + 1, n_r);
    return t1 + t2;
}

void solve() {
    int N;
    cin >> N >> M;

    vi v(N);
    for (int& x : v) cin >> x;

    vi dp(M + 1);
    vi a(N);

    for (int i = N - 1; ~i; --i) {
        int x = v[i];
        if (x > 0) {
            x += 6000;
            a[i] = query(1, 6000, x);
            upd(1, x, x, 1);
        } else if (x < 0) {
            x = abs(x);
            a[i] = query(1, 0, x);
            upd(1, x, x, 1);
        }
        ++a[i];
    }

    int c = 0, t = 0;
    for (int i = 0; i < N && t <= 2*M; ++i) {
        if (v[i] == 0) ++c, ++t;
        else if (v[i] > 0) {
            for (int j = 1; j <= min(c, v[i]); ++j) {
                dp[v[i]] = max(dp[v[i]], dp[v[i] - j] + a[i]);
            }
        } else {
            int x = t - abs(v[i]);
            for (int j = x + 1; j <= x + min(c, abs(v[i])); ++j) {
                dp[x] = max(dp[x], dp[j] + a[i]);
            }
        }
    }

    // ... 0 0 0 0 0 100 99 98 97
    int ans = 0;
    for (int i = 0; i <= M; ++i) {
        ans = max(ans, dp[i]);
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