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

void solve() {
    int N; cin >> N;
    set<vi> s;
    set<int> r;

    for (int i = 0; i < N; ++i) {
        int u, v;
        cin >> u >> v;
        s.insert({u, v, i});
    }

    for (int i = 1; i <= N; ++i) r.insert(i);

    int ans = 0;
    priority_queue<pi, vpi, greater<>> pq;
    vi asr(N);

    for (const vi& v : s) {
        int st = v[0], nd = v[1], i = v[2];
        while (pq.size()) {
            auto [st2, f2] = pq.top();
            if (st2 >= st) break;
            pq.pop();
            r.insert(f2);
        }
        int f = *r.begin();
        r.erase(f);
        pq.push({nd, f});
        asr[i] = f;
        ans = max(ans, (ll) pq.size());
    }
    cout << ans << '\n';
    for (int& x : asr) cout << x << ' ';
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
