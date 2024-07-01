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

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}


void solve() {
    int n; cin >> n;
    vi v(n);
    int m = 1;

    for (auto& x : v) {
        cin >> x;
        m = lcm(m, x);
    };
    --m;
    bool b = 0;
    int t = 0, c = 0, mn = INF;
    for (auto& x : v) {
        t = m/x + 1;
        c += t;
        mn = min(mn, t*x);
    }
    if (mn > c) {
        b = 1;
        for (auto& x : v) {
            cout << m/x + 1 << ' ';
        }
        cout << '\n';
    }
    if (!b) cout << -1 << '\n';
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
