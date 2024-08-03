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
    vi a(N), b(N);
    int mx = 0;
    for (int& x : a) {
        cin >> x;
        mx = max(mx, x);
    }
    for (int& x : b) cin >> x;

    int lo = 0, hi = mx+1;
    int ans = 0;

    auto gauss = [&](int l, int r) {
        return (r * (r+1) / 2) - (l * (l-1) / 2);
    };

    while (lo < hi) {
        int mi = (lo+hi) >> 1;
        int c = 0, z = 0, lowC = 0;
        for (int i = 0; i < N; ++i) {
            int diff = a[i] - mi;
            if (diff < 0) continue;
            int mod = a[i] % b[i];
            int st = (mi / b[i] * b[i]) + mod;
            if (st < mi) st += b[i];
            if (st == mi) ++lowC;
            if (b[i] >= a[i]) {
                z += a[i];
                ++c;
            } else {
                int l = st / b[i];
                int r = a[i] / b[i];
                c += (r-l + 1);
                z += gauss(l, r) * b[i] + mod * (r-l + 1); 
            }
        }
        if (c <= K) {
            ans = max(ans, z);
            hi = mi;
        } else {
            if (lowC >= (c - K)) {
                z -= (c-K) * (mi);
                ans = max(ans, z);
            }
            lo = mi+1;
        }
    }
    cout << ans << '\n';
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
