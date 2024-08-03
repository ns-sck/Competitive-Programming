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
const ll MAX = 1e7+1;

ll lp[MAX+1];
vector<ll> pr;
vector<bool> ipr(2*MAX);

void sieve() {
	for(ll i = 2; i < MAX; i++) {
		if(!lp[i]) {
			lp[i] = i;
			pr.push_back(i);
            ipr[2*i] = 1;
		}
		for(int j = 0; j < pr.size() && pr[j] <= lp[i] && i * pr[j] < MAX; j++) {
			lp[i * pr[j]] = pr[j];
		}
	}
}

void solve() {
	int N; cin >> N;
    sieve();
	while (N--) {
		int a; cin >> a;
        bool b = 1;
        for (int x = 1; x < 1000 && b; ++x) {
            for (int l = a-1; l >= max(0ll, (a-x)); --l) {
                int z = x*x + 2ll*x*l + x;
                if (z >= MAX) continue;
                if (ipr[z]) {
                    cout << x << '\n';
                    b = 0;
                    break;
                }
            }
        }
	}
    cout << ' ';
}

signed main () {

  	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
