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
#define s first
#define mx second
pi stx[2*MAX], sty[2*MAX];
int N, M, Q;
vi vx[MAX], vy[MAX];

void updx(int k, int x){
    k += N;
    stx[k].s = x; 
    stx[k].mx = x; 
    k >>= 1;
    while(k >= 1){
        stx[k].mx = max(stx[2*k].mx, stx[2*k+1].mx);
        stx[k].s = stx[2*k].s + stx[2*k+1].s;
        k >>= 1;
    }
}
void updy(int k, int x){
    k += M;
    sty[k].s = x; 
    sty[k].mx = x; 
    k >>= 1;
    while(k >= 1){
        sty[k].mx = max(sty[2*k].mx, sty[2*k+1].mx);
        sty[k].s = sty[2*k].s + sty[2*k+1].s;
        k >>= 1;
    }
}
ll qryx(int a, int b, bool qt){
    a += N, b += N;
    int ans = 0;
    while(a <= b){
        if (a&1) ans = qt ? max(ans, stx[a++].mx) : ans + stx[a++].s;
        if (~b&1) ans = qt ? max(ans, stx[b--].mx) : ans + stx[b--].s;
        a >>= 1, b >>= 1;
    }
    return ans;
}

ll qryy(int a, int b, bool qt){
    a += M, b += M;
    int ans = 0;
    while(a <= b){
        if (a&1) ans = qt ? max(ans, sty[a++].mx) : ans + sty[a++].s;
        if (~b&1) ans = qt ? max(ans, sty[b--].mx) : ans + sty[b--].s;
        a >>= 1, b >>= 1;
    }
    return ans;
}

int divide(int x1, int y1, int x2, int y2) {
    if (x1 == x2) return qryy(x1, x2-1, 0);
    if (x2 == x1+1) {
        
    }
}

void solve() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) cin >> vx[i];
    for (int i = 0; i < M; ++i) cin >> vy[i];
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
