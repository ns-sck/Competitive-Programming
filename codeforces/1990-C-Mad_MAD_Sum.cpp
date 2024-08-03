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
	int N; cin >> N;
    vi v(N);
    int sum = 0;
    for (int& x : v) cin >> x, sum += x;
    int b[N+1];
    memset(b, 0, sizeof(b));
    int csum = 0;
    int mad = 0;
    for (int i = 0; i < N; ++i) {
        if (b[v[i]]) {
            mad = max(mad, v[i]);
        } else {
            b[v[i]] = 1;
        }
        v[i] = mad;
        csum += v[i];
    }
    sum += csum;
    memset(b, 0, sizeof(b));
    csum = 0;
    mad = 0;
    for (int i = 0; i < N; ++i) {
        if (b[v[i]]) {
            mad = max(mad, v[i]);
        } else {
            b[v[i]] = 1;
        }
        v[i] = mad;
        csum += v[i];
    }
    for (int j = N-1; ~j; --j) {
        sum += csum;
        csum -= v[j];
    }
    cout << sum << '\n';
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
