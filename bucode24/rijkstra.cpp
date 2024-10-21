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
int N, M;

struct node {
    ll lazy = INF, mn = INF;
} st[800005];

void push(ll i, ll n_l, ll n_r) 
{
    st[i].mn = min(st[i].mn, st[i].lazy);
    if (n_l ^ n_r) {
        st[lch].lazy = min(st[i].lazy, st[lch].lazy);
        st[rch].lazy = min(st[i].lazy, st[rch].lazy);
    }
    st[i].lazy = INF;
}

void upd(ll i, ll q_l, ll q_r, ll val, ll n_l = 0, ll n_r = N-1) 
{
    push(i, n_l, n_r);
    if (n_l > q_r || n_r < q_l) return;

    if (n_l >= q_l && n_r <= q_r) {
        st[i].lazy = min(st[i].lazy, val);
        push(i, n_l, n_r);
        return;
    }

    int mid = (n_l + n_r) / 2;
    upd(lch, q_l, q_r, val, n_l, mid);
    upd(rch, q_l, q_r, val, mid+1, n_r);

    st[i].mn = min(st[lch].mn, st[rch].mn);
}

ll query(ll i, ll q_l, ll q_r, ll n_l = 0, ll n_r = N-1) 
{
    push(i, n_l, n_r);
    if (n_l > q_r || n_r < q_l) return INF;
    if (n_l >= q_l && n_r <= q_r) return st[i].mn;

    int mid = (n_l + n_r) / 2;
    ll t1 = query(lch, q_l, q_r, n_l, mid);
    ll t2 = query(rch, q_l, q_r, mid + 1, n_r);
    return min(t1, t2);
}

void solve() {

    cin >> N >> M;

    set<pi> s1;
    vvi edg;
    int i = 0;

    priority_queue<vi, vvi, greater<>> pq;

    for (int j = 0; j < N; ++j) {
        upd(1, j, j, INF);
    }

    while (M--) {
        int s, l, r, w;
        cin >> s >> l >> r >> w;
        --s, --l, --r;
        edg.pb({l, r, w});
        s1.insert({s, i});
        if (s == 0) pq.push({0, 0, i});
        ++i;
    }

    
    upd(1, 0, 0, 0);

    while (pq.size()) {
        vi vc = pq.top();
        pq.pop();

        int d = vc[0], u = vc[1], idx = vc[2];
        if (query(1, u, u) < d) continue;
        int l = edg[idx][0], r = edg[idx][1], w = edg[idx][2];
        upd(1, l, r, d + w);

        auto it = s1.lower_bound({l, -1});

        while (it != s1.end() && it->first <= r) {
            if (query(1, it->first, it->first) >= d + w) {
                pq.push({d + w, it->first, it->second});
            }
            auto it2 = it;
            ++it;
        }
    }

    for (int i = 0; i < N; ++i) {
        int x = query(1, i, i);
        if (x == INF) cout << -1 << ' ';
        else cout << x << ' ';
    } 

}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
