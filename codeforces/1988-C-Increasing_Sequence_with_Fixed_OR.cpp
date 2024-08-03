#include <bits/stdc++.h>
using namespace std;

template<typename... T>
void dbg(T&&... args) { ((cout << args << " "), ...); cout << '\n';}

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
	int N; cin >> N;
    if (__builtin_popcountll(N) == 1) {
        cout << 1 << '\n';
        cout << N << '\n';
        return;
    }

    vi ans = {N};
    int p = N;
    while (p) {
        int idx = __builtin_ffsll(p)-1;
        p &= ~(1ll<<idx);
        int a = N;
        for (int i = 0; i < idx; ++i) {
            if (N & (1ll<<i)) a |= (1ll<<i);
        }
        a &= ~(1ll<<idx);
        ans.pb(a);
    }
    cout << ans.size() << '\n';
    for (int i = ans.size()-1; ~i; --i)
        cout << ans[i] << ' ';
    cout << '\n';
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
