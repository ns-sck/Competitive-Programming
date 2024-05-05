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
const ll MAX = 1e2+1;
const ld EPS = 1e-9; 

ld dp[MAX][MAX][MAX];

ld rec(int r, int s, int p) {
    if (r == 0) return 0;
    if (s == 0 && p == 0) return dp[r][s][p] = 1;
    if (dp[r][s][p] != -1) return dp[r][s][p];
    ld rr = (r*p), ss = (s*r), pp = (p*s);
    ld t = rr+ss+pp;
    dp[r][s][p] = 0;
    if (p) dp[r][s][p] += (rr/t) * rec(r-1, s, p); 
    if (s) dp[r][s][p] += (ss/t) * rec(r, s-1, p); 
    if (s && p) dp[r][s][p] += (pp/t) * rec(r, s, p-1);
    return dp[r][s][p]; 
}

void solve() {
    int r, s, p;
    cin >> r >> s >> p;
    fill((ld*) dp, (ld*) dp + MAX*MAX*MAX, -1);
    cout << setprecision(12) << rec(r, s, p) << ' ';
    fill((ld*) dp, (ld*) dp + MAX*MAX*MAX, -1);
    cout << setprecision(12) << rec(s, p, r) << ' ';
    fill((ld*) dp, (ld*) dp + MAX*MAX*MAX, -1);
    cout << setprecision(12) << rec(p, r, s);
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
