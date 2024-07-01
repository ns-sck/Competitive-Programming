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

int a[26];
void solve() {
    int N; cin >> N;
    string S; cin >> S;
    int i = 0, j = 1;
    a[S[0]-'a'] = 1;
    int ans = 1, diff = 1;
    while (j < N) {
        int c = S[j]-'a';
        if (a[c]++ == 0) ++diff;
        if (a[c] <= diff) {
            ans = max(ans, j-i+1);
            ++j;
            continue;
        }
        int mxE = INF;
        while (i < j) {
            mxE = 0;
            for (int k = 0; k < 26; ++k) {
                mxE = max(mxE, a[k]);
            }
            if (mxE <= diff) break;
            if (--a[S[i]-'a'] == 0) {
                --diff;
            }
            ++i;
        }
        ++j;
    }
    cout << ans << '\n';
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
