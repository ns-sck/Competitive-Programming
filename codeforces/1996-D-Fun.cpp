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
	int N, X;
    cin >> N >> X;
    int ans = 0;
    for (int a = 1; a <= N-2; ++a) {
        for (int b = 1; b <= (N/a); ++b) {
            // ab + c(a+b) <= N
            // (N-ab) / (a+b) >= c
            // a + b + c <= X
            // X - a - b >= c;
            int c = X-a-b;
            c = min(c, (N-a*b) / (a+b));
            if (c >= 1) {
                ans += c;
            }
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
