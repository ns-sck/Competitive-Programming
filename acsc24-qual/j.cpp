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
const ll MAX = 5e6+2;
const ld EPS = 1e-9; 

#define lch 2*i
#define rch 2*i+1

int N, Q;

struct node {
    ll lazy, last;
} st[MAX<<2];

void push(ll i, ll n_l, ll n_r) 
{   
    if (st[i].lazy == 0) return;
    st[i].last = st[i].lazy * (n_r-n_l+1);
    if (n_l ^ n_r) {
        st[lch].lazy = st[i].lazy;
        st[rch].lazy = st[i].lazy;
    }
    st[i].lazy = 0;
}

void upd(ll i, ll q_l, ll q_r, ll val, ll n_l = 0, ll n_r = N-1) 
{
    push(i, n_l, n_r);
    if (n_l > q_r || n_r < q_l) return;

    if (n_l >= q_l && n_r <= q_r) {
        st[i].lazy = val;
        push(i, n_l, n_r);
        return;
    }

    int mid = (n_l + n_r) / 2;
    upd(lch, q_l, q_r, val, n_l, mid);
    upd(rch, q_l, q_r, val, mid+1, n_r);

    st[i].last = st[lch].last + st[rch].last;
}

ll query(ll i, ll q_l, ll q_r, ll n_l = 0, ll n_r = N-1) 
{
    push(i, n_l, n_r);
    if (n_l > q_r || n_r < q_l) return 0;
    if (n_l >= q_l && n_r <= q_r) return st[i].last;

    int mid = (n_l + n_r) / 2;
    ll t1 = query(lch, q_l, q_r, n_l, mid);
    ll t2 = query(rch, q_l, q_r, mid + 1, n_r);
    return t1 + t2;
}

void solve() {
    string S;
    cin >> S >> Q;
    N = S.size();
    
    string trg = "inzvaolsundagerisiboskalp";
    vi nd(26), cnt(26), prv(N, -1), nxt(N, INF), seen(26, -1);
    for (auto& c : trg) ++nd[c-'a'];
    int j = 0, b = 0;

    while (j < N) {
        bool b = 0;
        for (int i = 0; i < 26; ++i) b |= cnt[i]<nd[i];
        if (!b) break;
        ++cnt[S[j++]-'a'];
    }

    for (int i = 0; i < N; ++i) {
        int c = S[i]-'a';
        upd(1, i, i, min(j-1, N-1));
        --cnt[c];
        while (j < N && cnt[c]<nd[c]) {
            ++cnt[S[j]-'a'];
            ++j;
        }
        if (~seen[c]) {
            nxt[seen[c]] = i;
            prv[i] = seen[c];
        }
        seen[c] = i;
    }

    auto f = [&](int l, int r) {
        int x = l*(l+1)/2 - r*(r+1)/2 + (r-l+1) - l; 
        return x; 
    };
    
    auto bs = [&](int lo, int hi, int last) {
        int ans = -1;
        while (lo <= hi) {
            int mi = (lo+hi)>>1;
            int lst = query(1, mi, mi);
            if (lst >= last) hi = mi-1;
            else {
                lo = mi+1;
                ans = mi;
            }
        }
        return ans;
    };

    while (Q--) {
        int qt; cin >> qt;
        if (qt == 1) {
            int idx; cin >> idx;
            int l1, l2, l3, r1, r2, r3, c = S[--idx]-'a';
            if (c == 23) continue; // x
            S[idx] = 'x'; 
            l1 = prv[idx], r1 = nxt[idx];
            l2 = ~l1 ? prv[l1] : -1, r2 = r1 == INF ? INF : nxt[r1];
            l3 = ~l2 ? prv[l2] : -1, r3 = r2 == INF ? INF : nxt[r2];
            r1 = min(r1, N-1), r2 = min(r2, N-1), r3 = min(r3, N-1);
            if (nd[c] == 3) {
                if (l2 >= 0) {
                    int x = bs(l3+1, l2, r1);
                    if (x != -1) upd(1, l3+1, x, r1);
                }
                if (l1 >= 0) {
                    int x = bs(l2+1, l1, r2);
                    if (x != -1) upd(1, l2+1, x, r2);                     
                }
                if (idx >= 0) {
                    int x = bs(l1+1, idx, r3);
                    if (x != -1) upd(1, l1+1, x, r3);
                }
            } else if (nd[c] == 2) {
                if (l1 >= 0) {
                    int x = bs(l2+1, l1, r1);
                    if (x != -1) upd(1, l2+1, x, r1);
                }
                if (idx >= 0) {
                    int x = bs(l1+1, idx, r2);
                    if (x != -1) upd (1, l1+1, x, r2);
                }
            } else if (nd[c] == 1) {
                if (idx >= 0) {
                    int x = bs(l1+1, idx, r1);
                    if (x != -1) upd(1, l1+1, x, r1);
                }
            }
            if (nxt[idx] != INF) prv[nxt[idx]] = prv[idx];
            if (~prv[idx]) nxt[prv[idx]] = nxt[idx];
        } else {
            int l, r;
            cin >> l >> r;
            --l, --r;
            cout << (query(1, l, r) + f(l, r)) << '\n';
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
