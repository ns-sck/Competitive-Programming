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
 
ll st[MAX<<2];
int N;
 
void upd(int k, int x) {
    k += N<<1;
    st[k] += x; 
    k >>= 1;
    while(k >= 1){
        st[k] = st[2*k] + st[2*k+1];
        k >>= 1;
    }
}
ll qry(int a, int b) {
    a += N<<1, b += N<<1;
    int ans = 0;
    while(a <= b){
        if (a&1) ans += st[a++];
        if (~b&1) ans += st[b--];
        a >>= 1, b >>= 1;
    }
    return ans;
}
 
void solve() {
    cin >> N;
    vvi rng;
    map<int, int> mp;
    for (int i = 0; i < N; ++i) {
        int l, r;
        cin >> l >> r;
        mp[l] = 1, mp[r] = 1;
        rng.pb({l, r, i});
    }
 
    int i = 0;
    for (auto& p : mp) {
        p.second = i++;
    }
 
    for (int i = 0; i < N; ++i) {
        int l = rng[i][0], r = rng[i][1];
        rng[i][0] = mp[l], rng[i][1] = -mp[r];
    }
 
    sort(all(rng));
    vi av1(N), av2(N);
    
    for (int i = 0; i < N; ++i) {
        rng[i][1] = -rng[i][1];
        int r = rng[i][1], idx = rng[i][2];
        int q = qry(r, (N<<1)-1);
        av2[idx] = q;
        upd(r, 1);
    }
    memset(st, 0, sizeof(st));

    for (int i = N-1; ~i; --i) {
        int l = rng[i][0], r = rng[i][1], idx = rng[i][2];
        int q = qry(0, r);
        av1[idx] = q;
        upd(r, 1);
    }
 
    for (int i = 0; i < N; ++i) {
        cout << (av1[i]>0) << ' ';
    }

    cout << '\n';

    for (int i = 0; i < N; ++i) {
        cout << (av2[i]>0) << ' ';
    }
}
 
signed main () {
 
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();
 
	return 0;
}
