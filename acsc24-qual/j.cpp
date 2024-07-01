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
const ll MAX = 2e5+1;
const ld EPS = 1e-9; 

#define lch 2*i
#define rch 2*i+1

string s;

struct node {
    ll lazy, sum;
} st[26][1<<19];

void push(ll i, ll n_l, ll n_r, int x) {
    st[x][i].sum += st[x][i].lazy;
    if (n_l ^ n_r) {
        st[x][lch].lazy += st[x][i].lazy;
        st[x][rch].lazy += st[x][i].lazy;
    }
    st[x][i].lazy = 0;
}

void upd(ll i, ll n_l, ll n_r, ll q_l, ll q_r, ll val, int x) {
    push(i, n_l, n_r, x);
    if (n_l > q_r || n_r < q_l) return;

    if (n_l >= q_l && n_r <= q_r) {
        st[x][i].lazy += val;
        push(i, n_l, n_r, x);
        return;
    }

    int mid = (n_l + n_r) / 2;
    upd(lch, n_l, mid, q_l, q_r, val, x);
    upd(rch, mid + 1, n_r, q_l, q_r, val, x);

    st[x][i].sum = st[x][lch].sum + st[x][rch].sum;
}

ll query(ll i, ll n_l, ll n_r, ll q_l, ll q_r, int x) {
    push(i, n_l, n_r, x);
    if (n_l > q_r || n_r < q_l) return 0;
    if (n_l >= q_l && n_r <= q_r) return st[x][i].sum;

    int mid = (n_l + n_r) / 2;
    ll t1 = query(lch, n_l, mid, q_l, q_r, x);
    ll t2 = query(rch, mid + 1, n_r, q_l, q_r, x);
    return t1 + t2;
}

void build(ll i, ll n_l, ll n_r, int x) {
    if (n_l == n_r) {
        st[x][i].sum = (s[n_l] == 'a' + x);
        return;
    }
    int mid = n_l + (n_r - n_l) / 2;
    build(lch, n_l, mid, x);
    build(rch, mid + 1, n_r, x);
    st[x][i].sum = st[x][lch].sum + st[x][rch].sum;
}

void solve() {
    cin >> s;
    int N = s.size();
    int Q; cin >> Q;
    string ss = "inzvaolsundagerisiboskalp";
    for (int i = 0; i < 26; ++i) {
        build(1, 0, N-1, i);
    }
    cout << query(1, 0, N-1, 0, N-1, 0);
    vi a(26);
    for (auto c : ss) ++a[c-'a'];

    vi pre(N, N+1);
        for (int i = 0; i < N-24; ++i) {
            int ans = 0;
            for (int j = 0; j < 26; ++j) {
                if (!a[j]) continue;
                int lo = i, hi = N, mn = N+1;
                while (lo < hi) {
                    int m = (lo+hi)>>1;
                    if (m == N) break;
                    int q = query(1, 0, N-1, i, m, j);
                    if (q < a[j]) lo = m+1;
                    else {
                        mn = min(mn, m);
                        hi = m;
                    }
                }
                ans = max(ans, mn);
            }
            pre[i] = ans;
        }

    while (Q--) {
        int qt; cin >> qt;
        if (qt == 1) {
            int i; cin >> i;
            if (!a[s[i]]) continue;
            upd(1, 0, N-1, i-1, i-1, -1, s[i]-'a');
            s[i] = 'x';
        } else {
            int l, r;
            cin >> l >> r;
            --l, --r;
            
        }
    }
}

signed main () {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}
