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
const ll MAX = 1e6+1;
const ld EPS = 1e-9; 

#define lch 2*i
#define rch 2*i+1

ll x[MAX], prfx[MAX], prfx2[MAX];

struct node {
    ll lazy, mx, mx2;
} st[1 << 23];

ll query(ll i, ll n_l, ll n_r, ll q_l, ll q_r, bool qt) 
{
    if (n_l > q_r || n_r < q_l) return 0;
    if (n_l >= q_l && n_r <= q_r) return (qt ? st[i].mx2 : st[i].mx);

    int mid = (n_l + n_r) / 2;
    ll t1 = query(lch, n_l, mid, q_l, q_r, qt);
    ll t2 = query(rch, mid + 1, n_r, q_l, q_r, qt);
    return t1+t2;
}

void build(ll i, ll n_l, ll n_r) 
{
    if (n_l == n_r) {
        st[i].mx = max(0ll, prfx[n_l]);
        st[i].mx2 = max(0ll, prfx2[n_l]);
        return;
    }
    int mid = n_l + (n_r - n_l) / 2;
    build(lch, n_l, mid);
    build(rch, mid + 1, n_r);
    st[i].mx = (st[lch].mx + st[rch].mx);
    st[i].mx2 = (st[lch].mx2 + st[rch].mx2);
}

void solve() {
    int N, K; 
    cin >> N >> K;
    vi v(N);
    for (auto& x : v) cin >> x;
    for (int i = 0; i < N-1; ++i) {
        prfx[i] = v[i+1] - v[i];
        prfx2[i] = -prfx[i];
    }
    build(1, 0, N-2);
    for (int i = K-1; i < N; ++i) {
        ld x = max(0ll, query(1, 0, N-2, i-K+1, i-1, 0)) + 0.0;
        ld y = max(0ll, query(1, 0, N-2, i-K+1, i-1, 1)) + 0.0;
        ld v = (x == 0) ? 0 : (x*100 / (x+y));
        int a = (v > 65 ? 2 : (v < 35 ? 1 : 0));
        cout << fixed << setprecision(1) << v << ' ' << a << '\n';
    }
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
