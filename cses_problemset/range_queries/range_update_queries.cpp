#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>
#define vi vector<int>
#define vii vector<vector<int>>
#define vpi vector<pi>
#define pb push_back
#define ar array
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const ll MOD = 1e9+7;
const ll INF = 1e18;
const ll MAX = 2e5+1;
const long double EPS = 1e-9; 

int n, q;
ll x[MAX];

struct node {
    ll mn, s, lz;
} st[1 << 19];

void app(int i, ll x, int l2, int r2) {
    st[i].mn += x;
    st[i].s += x*(r2-l2+1);
    st[i].lz += x;
}

void psh(int i, int l2, int m2, int r2) {
    app(2*i, st[i].lz, l2, m2);
    app(2*i+1, st[i].lz, m2+1, r2);
    st[i].lz = 0;
}

void upd(int l1, ll x, int i = 1, int l2 = 0, int r2 = n-1) {
    if (l2 == r2) {
        st[i].mn = x;
        st[i].s += x;
        return;
    }
    int m2 = (l2+r2)/2;
    psh(i, l2, m2, r2);
    if (l1 <= m2)
        upd(l1, x, 2*i, l2, m2);
    else
        upd(l1, x, 2*i+1, m2+1, r2);
    st[i].mn = min(st[2*i].mn, st[2*i+1].mn);
    st[i].s = st[2*i].s + st[2*i+1].s;
}

void upd2(int l1, int r1, ll x, int i = 1, int l2 = 0, int r2 = n-1) {
    if (l1 <= l2 && r2 <= r1) {
        app(i, x, l2, r2);
        return;
    }
    int m2 = (l2+r2)/2;
    psh(i, l2, m2, r2);
    if (l1 <= m2) 
        upd2(l1, r1, x, 2*i, l2, m2);
    if (m2 < r1)
        upd2(l1, r1, x, 2*i+1, m2+1, r2);
    st[i].mn = min(st[2*i].mn, st[2*i+1].mn);
    st[i].s = st[2*i].s + st[2*i+1].s;
}

ll qry(int l1, int r1, int i = 1, int l2 = 0, int r2 = n-1) {
    if (l1 <= l2 && r2 <= r1) {
        // return st[i].mn;
        return st[i].s;
    }
    int m2 = (l2+r2)/2;
    psh(i, l2, m2, r2);
    // return min(l1 <= m2 ? qry(l1, r1, 2*i, l2, m2) : int(1e9), m2 < r1 ? qry(l1, r1, 2*i+1, m2+1, r2) : int(1e9));
    return (l1 <= m2 ? qry(l1, r1, 2*i, l2, m2) : 0) + (m2 < r1 ? qry(l1, r1, 2*i+1, m2+1, r2) : 0);
}

void solve() {
    cin >> n >> q;
    for (int i = 0; i < n; ++i)
        cin >> x[i], upd(i, x[i]);
    
    while (q--) {
        int qt; cin >> qt;
        if (qt == 2) {
            int k; cin >> k;
            --k;
            cout << qry(k, k) << '\n';
        }
        else {
            int a, b, u;
            cin >> a >> b >> u;
            --a, --b;
            upd2(a, b, u);
        }
    }
}   

int main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
