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
	int N, X, Y;
    cin >> N >> X >> Y;
    --X, --Y;
    vi ans(N);
    ans[X] = 1;
    ans[Y] = 1;
    for (int i = Y-1; ~i; --i) {
        ans[i] = -ans[i+1];
    }
    for (int i = Y+1; i < X; ++i) {
        ans[i] = 1;
    }
    for (int i = X+1; i < N; ++i) {
        ans[i] = -ans[i-1];
    }
    assert(ans[X] == 1 && ans[Y] == 1);
    for (auto& x : ans) cout << x << ' ';
    cout << '\n';
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
