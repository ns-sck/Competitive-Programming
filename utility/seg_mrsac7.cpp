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
const ll MAX = 20;
const long double EPS = 1e-9; 

ll st[2*MAX];
int n, q;

void upd(int k, int x){
    k += n;
    st[k] = x; 
    k >>= 1;
    while(k >= 1){
        st[k] = max(st[2*k], st[2*k+1]);
        k >>= 1;
    }
}
ll qry(int a, int b){
    a += n, b += n;
    int ans = 0;
    while(a <= b){
        if (a&1) ans = max(ans, st[a++]);
        if (~b&1) ans = max(ans, st[b--]);
        a >>= 1, b >>= 1;
    }
    return ans;
}

void solve() {
    cin >> n;
    vpi v(n);
    for (int i = 0; i < n; ++i) cin >> v[i].first;
    for (int i = 0; i < n; ++i) cin >> v[i].second;
    for (int i = 0; i < n; ++i) upd(v[i].first-1, qry(0, v[i].first-1) + v[i].second);
    cout << qry(0, n-1);
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}