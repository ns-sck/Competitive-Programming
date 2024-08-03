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
const ll MAX = 1e5+1;

void solve() {
    int N, Q;
    cin >> N >> Q;
    string S; cin >> S;
    vvi prfx(26, vi(N+1));

    for (int i = 0; i < 26; ++i) {
        for (int j = 1; j <= S.size(); ++j) {
            prfx[i][j] += prfx[i][j-1] + (S[j-1]-'a' == i);
        }
    }
    while (Q--) {
        int l, r;
        cin >> l >> r;
        char c; cin >> c;
        c -= 'a';
        cout << (c+1) * (prfx[c][r] - prfx[c][l-1]) << '\n';
    }
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
