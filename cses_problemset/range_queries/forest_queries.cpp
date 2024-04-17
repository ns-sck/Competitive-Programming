#include <bits/stdc++.h>
using namespace std;

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
const ll MAX = 1e3+1;
const long double EPS = 1e-9; 

int n, q;
int g[MAX][MAX];
void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            char c; cin >> c;
            g[i][j] = c == '*';
            g[i][j] += g[i-1][j] + g[i][j-1] - g[i-1][j-1];
        }
    
    while (q--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        --r1, --c1;
        cout << g[r2][c2] - g[r2][c1] - g[r1][c2] + g[r1][c1] << '\n';
    }
}

int main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
