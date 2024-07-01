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
const ll MAX = 1e4+1;
bool vis[MAX];
vvi v(MAX, vi(4));
int ans = 0;
void dfs(int val, int a, int b, int c) {
    ans = max(ans, val);
    vis[val] = 1;
    int y = (a*val+b)%c;
    if (!vis[y])
        dfs(y, a, b, c);
    vis[val] = 0;
}
void solve() {
    int N; cin >> N;
    ll x = 0;
    ll anss = 0;
    for (int i = 0; i < N; ++i) {
        ans = 0;
        for (int j = 0; j < 4; ++j) {
            cin >> v[i][j];
        }
        int a = v[i][1], b = v[i][2], c = v[i][3];
        int st = (v[i][0]*a+b)%c;
        ans = max(st, v[i][0]);
        dfs(v[i][0], v[i][1], v[i][2], v[i][3]);
        anss += ans;
    }
    cout << anss;
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
