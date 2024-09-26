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
const ll MAX = 1e6+1;

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
    int N, K;
    cin >> N >> K;

    sieve();

    int ans = 0;

    for (int& i : pr) {
        if (i > N) break;
        int x = (i - 1) >> 1;
        auto it = upper_bound(all(pr), x);
        int a = *it, b = *(--it);
        ans += (a + b == i - 1);
    }
    
    if (ans >= K) cout << "TRUE\n";
    else cout << "FALSE\n";
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