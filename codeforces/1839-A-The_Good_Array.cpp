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
	int N, K;
    cin >> N >> K;
    vi v(101);
    int c = 0;
    for (int i = 1; i <= N; ++i) {
        if ((i-1) / K + 1 > c) v[i] = 1;
        c += v[i];
    }
    c = 0;
    for (int i = 1; i <= N; ++i) {
        if ((i-1) / K + 1 > c) v[N-i+1] = 1;
        c += v[N-i+1];
    }
    int ans = 0;
    for (int i = 1; i <= N; ++i) ans += v[i];
    cout << ans << '\n';
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
