#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pi pair<int, int>
#define vi vector<int>
#define vii vector<vector<int>>
#define vpi vector<pi>
#define pb push_back
#define ar array
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const int _mod = 1e9+7;
const int _inf = 1e18;
const int _max = 2e5+1;
const long double _eps = 1e-9; 
vi pos(_max), v(_max);
int n, m; 
int upd(int a, int b) {
    int x = v[a];
    int y = v[b];
    int old = 0, nw = 0;
    if (x > y) swap(x,y);
    if (abs(x-y) <= 1) {

        if (x > 1) old += pos[x-1] > pos[x];
        old += pos[x] > pos[y];
        if (y < n) old += pos[y] > pos[y+1];
        swap(pos[x], pos[y]);
        if (x > 1) nw += pos[x-1] > pos[x];
        nw += pos[x] > pos[y];
        if (y < n) nw += pos[y] > pos[y+1];
        swap(v[a], v[b]);
        return nw - old;
    }
    if (x > 1) old += pos[x-1] > pos[x];
    old += pos[x] > pos[x+1];
    old += pos[y-1] > pos[y];
    if (y < n) old += pos[y] > pos[y+1];
    swap(pos[x], pos[y]);
    if (x > 1) nw += pos[x-1] > pos[x];
    nw += pos[x] > pos[x+1];
    nw += pos[y-1] > pos[y];
    if (y < n) nw += pos[y] > pos[y+1];
    swap(v[a], v[b]);
    return nw - old;
}
void solve() {
    
    cin >> n >> m;
    int ans = 1;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        pos[x] = i;
        v[i] = x;
    }
    for (int i = 2; i <= n; ++i) {
        if (pos[i] < pos[i-1]) ++ans;
    }
    while (m--) {
        int a, b;
        cin >> a >> b;
        ans += upd(a, b);
        cout << ans << '\n';
    }
}

int32_t main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
