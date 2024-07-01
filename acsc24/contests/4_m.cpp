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
    const ll MAX = 1e5+3;
    const ld EPS = 1e-9; 

    #define lch 2*i
    #define rch 2*i+1

    ll x[MAX], ans1[MAX], ans2[MAX];
    int N, Q;
    map<int, int> mp;

    struct node {
        ll lazy, sum;
    } st[1<<19];

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

    void upd(ll i, ll q_l, ll q_r, ll val, ll n_l = 0, ll n_r = N-1) 
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

    ll query(ll i, ll q_l, ll q_r, ll n_l = 0, ll n_r = N-1) 
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

    void solve() {
        cin >> N;
        vi v(N);
        for (int i = 0; i < N; ++i) cin >> x[i], mp[x[i]];
        int j = -1;
        for (auto& pr : mp) {
            pr.second = ++j;
        }
        for (int i = 0; i < N; ++i) {
            ans1[i] = query(1, mp[x[i]], N-1);
            upd(1, mp[x[i]], mp[x[i]], 1);
        }
        memset(st, 0, sizeof(st));
        for (int i = N-1; ~i; --i) {
            ans2[i] = query(1, mp[x[i]], N-1);
            upd(1, mp[x[i]], mp[x[i]], 1);
        }
        int ans = 0;
        for (int i = 0; i < N; ++i) {
            int mx = max(ans1[i], ans2[i]), mn = min(ans1[i], ans2[i]);
            if (max(ans1[i], ans2[i]) > min(ans1[i], ans2[i])*2) ++ans;
        }
        cout << ans << '\n';    
    }

    signed main () {

        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        
        int t = 1;
        // cin >> t;
        while (t--) solve();

        return 0;
    }
