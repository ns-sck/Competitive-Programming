#include <bits/stdc++.h>
using namespace std;

#define int long long
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
const ll MAX = 3e3+1;
const long double EPS = 1e-9; 

vi st;
int N, Q;

void upd(int k, int x){
    k += N;
    st[k] = x; 
    k >>= 1;
    while(k >= 1){
        st[k] = max(st[2*k], st[2*k+1]);
        k >>= 1;
    }
}

ll qry(int a, int b){
    a += N, b += N;
    int ans = 0;
    while(a <= b){
        if (a&1) ans = max(ans, st[a++]);
        if (~b&1) ans = max(ans, st[b--]);
        a >>= 1, b >>= 1;
    }
    return ans;
}

void solve() {
    cin >> n >> q;
    vi v(n);
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        upd(i, x);
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << qry(l-1, r-1) << ' ';
    }
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}