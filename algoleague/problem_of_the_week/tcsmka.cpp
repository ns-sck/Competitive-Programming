#include <bits/stdc++.h>
using namespace std;

template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...); cout << '\n';}

#define int long long
#define ll long long
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
const ll MAX = 1e4;

ll lp[MAX+1];
vector<ll> pr;

void sieve() {
	for(ll i = 2; i < MAX; i++) {
		if(!lp[i]) {
			lp[i] = i;
			pr.push_back(i);
		}
		for(int j = 0; j < pr.size() && pr[j] <= lp[i] && i * pr[j] < MAX; j++) {
			lp[i * pr[j]] = pr[j];
		}
	}
}

void solve() {
    int N; cin >> N;

    sieve();
    int ans = 0;

    for (int& x : pr) {
        int y = x * x * x * x * x;
        if (y < 0) break;
        for (int i = 1; i <= x; ++i) {
            if (y * i < 0 || y * i > N) break;
            ++ans;
        }
    }

    cout << ans << '\n';

}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}