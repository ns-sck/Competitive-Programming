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
const ll MAX = 1e7+3;

void solve() {
	ll H, M;
    cin >> H >> M;
    ll c = 59-M+1;
	c %= 60;
	ll trg = 60*H+M;
	vi dv;
	if (M == 59) {
		cout << "YES\n";
		return;
	} 
	for (int i = 1; i*i <= trg; ++i) {
		if (trg % i) continue;
		if ((trg/i) % 60 == 59) {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
