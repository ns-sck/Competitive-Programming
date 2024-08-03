#include <bits/stdc++.h>
using namespace std;

template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...); cout << '\n';}

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

void solve() {
	int N, Q;
    cin >> N >> Q;
    string A, B;
    cin >> A >> B;
    vvi prfxA(N+1, vi(26));
    vvi prfxB(N+1, vi(26));
    for (int i = 0; i < N; ++i) {
        int c1 = A[i]-'a';
        int c2 = B[i]-'a';
        for (int j = 0; j < 26; ++j) {
            prfxA[i+1][j] = prfxA[i][j] + (c1 == j);
            prfxB[i+1][j] = prfxB[i][j] + (c2 == j);
        }
    }
    while (Q--) {
        int l, r;
        cin >> l >> r;
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            int haveA = prfxA[r][i] - prfxA[l-1][i];
            int haveB = prfxB[r][i] - prfxB[l-1][i];
            int diff = haveA - haveB;
            if (diff > 0) ans += diff;
        }
        cout << ans << '\n';
    }
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
