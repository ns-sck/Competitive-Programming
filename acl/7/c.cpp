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
const ll MAX = 61;

ll lp[MAX+1];
vector <ll> pr;

void sieve() {
	for(ll i = 2; i <= MAX; i++) {
		if(!lp[i]) {
			lp[i] = i;
			pr.push_back(i);
		}
		for(int j = 0; j < pr.size() && pr[j] <= lp[i] && i * pr[j] <= MAX; j++) {
			lp[i * pr[j]] = pr[j];
		}
	}
}

vi prs[MAX];
set<int> qprs;
vector<int> qprsv;
int ans = 0;
void dfs(int i, int t, int msk) {
    if (i == qprsv.size()) {
        ans = max(ans, t);
        return;
    }
    ans = max(ans, t);
    int cpr = qprsv[i];
    for (int j = 0; j < prs[cpr].size(); ++j) {
        int crn = prs[cpr][j];
        if (msk & (1ll<<crn)) continue;
        int z = crn;
        int tsk = msk;
        while (z > 1) {
            int y = lp[z];
            for (int i = y; i < 63; i += y) {
                tsk |= (1ll<<i);
            }
            while (lp[z] == y) z /= y;
        }
        dfs(i+1, t+crn, tsk);
    }
    dfs(i+1, t, msk);
}
void solve() {
    int N; cin >> N;
    bool b = 0;
    sieve();
    while (N--) {
        int x; cin >> x;
        if (x == 1) b = 1;
        int z = x;
        while (x > 1) {
            int y = lp[x];
            qprs.insert(y);
            prs[y].pb(z);
            while (lp[x] == y) x /= y;
        }
    }
    for (auto& x : qprs) qprsv.pb(x);
    dfs(0, 0, 0);
    cout << ans+b << '\n';
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
