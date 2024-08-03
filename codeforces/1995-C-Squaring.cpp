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

int fp(int base, int exp) {
    int rval = 1LL;
    while (exp) {
        if (exp & 1) {
            rval *= base;
            rval %= MOD;
        }
        base *= base;
        base %= MOD;
        exp >>= 1;
    }
    return rval;
}

void solve() {
	int N; cin >> N;
    vi v(N), v2(N);
    for (int& x : v) cin >> x;
    int ans = 0;
    for (int i = 1; i < N; ++i) {
        int pc = v2[i-1], px = v[i-1];
        int x = v[i], c = 0;
        if (x == 1 && px > x) {
            cout << -1 << '\n';
            return;
        }
        if (x < px) {
            while (x < px) {
                x *= x;
                ++c;
            }
            v2[i] = c + pc;
            ans += c + pc;
        } else {
            while (px < x && px != 1 && c < pc) {
                px *= px;
                ++c;
            }
            v2[i] = pc - c + (x < px);
            ans += pc - c + (x < px);
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
