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

vi s(20), c(20);
int N, M;
bool b = 0;
void dfs(vector<int> v, int t = 0) {
    if (t == N) {
        b = 1;
        return;
    }
    for (int i = 0; i < (1<<v.size()); ++i) {
        int c = 0;
        vi v2;
        for (int j = 0; j < v.size(); ++j) {
            if ((1<<j)&i) {
                c += v[j];
            } else v2.pb(v[j]);
        }
        if (c == s[t]) {
            dfs(v2, t+1);
        }
    }
}

void solve() {
    
    int Q; cin >> Q;
    while (Q--) {
        cin >> N >> M;
        s.resize(N), c.resize(M);
        for (int i = 0; i < N; ++i) cin >> s[i];
        for (int i = 0; i < M; ++i) cin >> c[i];
        dfs(c, 0);
        if (b) {
            cout << "YES\n";
            b = 0;
        } else cout << "NO\n";
    }
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
