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
const ll MAX = 1e5+5;
const ld EPS = 1e-9; 

#define lch 2*i
#define rch 2*i+1

ll x[MAX], lazy[MAX];

struct node {
    ll sum, sfx, prfx, mx;
} st[1<<19];

void upd(int i, int n_l, int n_r, int q_l, int q_r, int val) 
{
    if (n_l > q_r || n_r < q_l) return;

    if (n_l == n_r) {
        st[i].mx = val;
        st[i].prfx = val;
        st[i].sfx = val;
        st[i].sum = val;
        return;
    }

    int mid = (n_l + n_r) / 2;
    upd(lch, n_l, mid, q_l, q_r, val);
    upd(rch, mid+1, n_r, q_l, q_r, val);

    st[i].sum = st[lch].sum + st[rch].sum;
    st[i].prfx = max(st[lch].prfx, st[lch].sum + st[rch].prfx);
    st[i].sfx = max(st[rch].sfx, st[rch].sum + st[lch].sfx);
    st[i].mx = max({st[lch].mx, st[rch].mx, st[lch].sfx + st[rch].prfx});
}

int query(int i, int n_l, int n_r, int q_l, int q_r) 
{
    if (n_l > q_r || n_r < q_l) return 0;
    if (n_l >= q_l && n_r <= q_r) return st[i].mx;

    int mid = (n_l + n_r) / 2;
    int t1 = query(lch, n_l, mid, q_l, q_r);
    int t2 = query(rch, mid + 1, n_r, q_l, q_r);
    return max(t1, t2);
}

void build(int i, int n_l, int n_r) 
{
    if (n_l == n_r) {
        st[i].mx = x[n_l];
        st[i].sfx = x[n_l];
        st[i].prfx = x[n_l];
        st[i].sum = x[n_l];
        return;
    }
    int mid = n_l + (n_r - n_l) / 2;
    build(lch, n_l, mid);
    build(rch, mid + 1, n_r);   
    st[i].sum = st[lch].sum + st[rch].sum;
    st[i].prfx = max(st[lch].prfx, st[lch].sum + st[rch].prfx);
    st[i].sfx = max(st[rch].sfx, st[rch].sum + st[lch].sfx);
    st[i].mx = max({st[lch].mx, st[rch].mx, st[lch].sfx + st[rch].prfx});
}

void solve() {
    int N, Q;
    cin >> N >> Q;
    cin >> x[0];
    for (int i = 1; i < N; ++i) {
        cin >> x[i];
    }
    build(1, 0, N-1);
    while (Q--) {
        int k, u;
        cin >> k >> u;
        --k;
        upd(1, 0, N-1, k, k, u);
        x[k] = u;
        ll s = query(1, 0, N-1, 0, N-1);
        s = max(0LL, s);
        cout << s << '\n';

    }
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
