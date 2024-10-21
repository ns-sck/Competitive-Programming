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

ll x[MAX];
int N, Q;

struct node {
    ll lazy;
    ll sum;
    // ll mn;
    // ll mx;
} st[1 << 19];

// void print_st() {
//     ll str = 1;
//     ll lc = 1;
//     for (ll lv = 0; lv < 4; lv++) {
//         for (ll i = str; i < str + lc; i++) {
//             printf("[%lli], ", st[i].sum);
//         }
//         printf("\n");
//         str += lc;
//         lc *= 2;
//     }
// }

void push(ll i, ll nl, ll nr) 
{
    st[i].sum += (st[i].lazy * (nr - nl + 1));
    // st[i].mn += st[i].lazy;
    // st[i].mx += st[i].lazy;

    if (nl ^ nr) {
        st[lch].lazy += st[i].lazy;
        st[rch].lazy += st[i].lazy;
    }
    st[i].lazy = 0;
}

void upd(ll ql, ll qr, ll val, ll i = 1, ll nl = 0, ll nr = N - 1) 
{
    push(i, nl, nr);
    if (nl > qr || nr < ql) return;

    if (nl >= ql && nr <= qr) {
        st[i].lazy += val;
        push(i, nl, nr);
        return;
    }

    int mid = (nl + nr) / 2;
    upd(ql, qr, val, lch, nl, mid);
    upd(ql, qr, val, rch, mid + 1, nr);

    st[i].sum = st[lch].sum + st[rch].sum;
    // st[i].mn = min(st[lch].mn, st[rch].mn);
    // st[i].mx = max(st[lch].mx, st[rch].mx);
}

ll query(ll ql, ll qr, ll i = 1, ll nl = 0, ll nr = N - 1) 
{
    push(i, nl, nr);
    if (nl > qr || nr < ql) return 0;
    // if (nl > qr || nr < ql) return INF;
    // if (nl > qr || nr < ql) return -INF;

    if (nl >= ql && nr <= qr) return st[i].sum;
    // if (nl >= ql && nr <= qr) return st[i].mn;
    // if (nl >= ql && nr <= qr) return st[i].mx;

    int mid = (nl + nr) / 2;
    ll t1 = query(ql, qr, lch, nl, mid);
    ll t2 = query(ql, qr, rch, mid + 1, nr);

    return t1 + t2;
    // return min(t1, t2);
    // return max(t1, t2);
}

// ll bs(ll x, int i = 1, int nl = 0, int nr = N - 1) {

//     if (nl == nr)
//         return nl;

//     int m = (nl + nr) / 2;

//     push(i, nl, nr);
//     if (st[lch].mx >= x)
//         return bs(x, lch, nl, m);

//     return bs(x, rch, m + 1, nr);
// }

void solve() {
    cin >> N >> Q;
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
