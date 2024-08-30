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
    vi v(N);
    for (int& x : v) cin >> x;
    sort(all(v));
    int l = v[N-1], lo = l, hi = v[N-1]+K;
    int a = K;
    for (int i = 0; i < N-1; ++i) {
        int x = (l - v[i]) / K;
        x += (l - v[i]) % K != 0;
        if (x & 1) {
            hi = min(hi, v[i]+(x*K)-1);
        } else {
            lo = max(lo, v[i]+(x*K));
        }
    }
    if (lo <= hi) {
        cout << lo << '\n';
    } else {
        cout << -1 << '\n';
    }
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
