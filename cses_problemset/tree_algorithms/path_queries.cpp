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
const ll MAX = 4e5+1;
const ld EPS = 1e-9; 

#define lch 2*i
#define rch 2*i+1

ll x[MAX];
int N, Q;

struct node {
    ll lazy, sum;
} st[1<<20];

void print_st() {
    ll str = 1;
    ll lc = 1;
    for (ll lv = 0; lv < 4; lv++) {
        for (ll i = str; i < str + lc; i++) {
            printf("[%lli], ", st[i].sum);
        }
        printf("\n");
        str += lc;
        lc *= 2;
    }
}

void push(ll i, ll n_l, ll n_r) 
{
    st[i].sum += st[i].lazy;
    if (n_l ^ n_r) {
        st[lch].lazy += st[i].lazy;
        st[rch].lazy += st[i].lazy;
    }
    st[i].lazy = 0;
}

void upd(ll i, ll q_l, ll q_r, ll val, ll n_l = 0, ll n_r = 2 * N-1) 
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

ll query(ll i, ll q_l, ll q_r, ll n_l = 0, ll n_r = 2 * N-1) 
{
    push(i, n_l, n_r);
    if (n_l > q_r || n_r < q_l) return 0;
    if (n_l >= q_l && n_r <= q_r) return st[i].sum;

    int mid = (n_l + n_r) / 2;
    ll t1 = query(lch, q_l, q_r, n_l, mid);
    ll t2 = query(rch, q_l, q_r, mid + 1, n_r);
    return t1 + t2;
}

void build(ll i, ll n_l, ll n_r) 
{
    if (n_l == n_r) {
        st[i].sum = x[n_l];
        return;
    }
    int mid = n_l + (n_r - n_l) / 2;
    build(lch, n_l, mid);
    build(rch, mid + 1, n_r);
    st[i].sum = st[lch].sum + st[rch].sum;
}

vi adj[MAX];
int l[MAX], r[MAX], t = 0, val[MAX];

void dfs(int u, int p = -1, int d = 0) {
    l[u] = t;
    d += val[u];
    x[t++] = d;

    for (auto v : adj[u]) {
        if (v == p) continue;
        dfs(v, u, d);
    }

    r[u] = t;
    x[t++] = d;
}

void solve() {
    cin >> N >> Q;

    int nn = N;
    
    for (int i = 0; i < N; ++i) {
        cin >> val[i];
    }

    for (int i = 1; i < N; ++i) {
        int u, v;
        cin >> u >> v;
        adj[--u].pb(--v);
        adj[v].pb(u);
    }

    dfs(0);
    for (int i = 0; i < 2 * N; ++i) {
        upd(1, i, i, x[i]);
    }
    

   while (Q--) {
        int a; cin >> a;
        if (a == 1) {
            int u, b;
            cin >> u >> b;
            --u;
            upd(1, l[u], r[u], b - val[u]);
            val[u] = b;
        } else {
            int u; cin >> u;
            --u;
            cout << query(1, l[u], l[u]) << '\n';
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
