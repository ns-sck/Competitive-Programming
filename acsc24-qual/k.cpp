#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,
             tree_order_statistics_node_update>;

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
const ld EPS = 1e-9; 

void solve() {
    int N, M;
    cin >> N >> M;
    oset<int> ost;
    priority_queue<pi, vpi, greater<>> pq;

    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        pq.push({x, y});
        ost.insert(x+y);
    }

    vector<ar<int, 3>> qs;
    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        qs.pb({x, y, i});
    }

    sort(all(qs));
    vi av(M);

    for (int i = 0; i < M; ++i) {
        int x = qs[i][0], k = qs[i][1], idx = qs[i][2];

        while (pq.size() && pq.top().first <= x) {
            auto [xi, yi] = pq.top();
            pq.pop();
            auto it = ost.lower_bound(xi+yi);
            ost.erase(it);
            ost.insert(xi-yi);
        }

        int lo = 0, hi = N-k, ans = INF;

        while (lo < hi) {
            int m = (lo+hi)>>1;
            int st = abs(x - *ost.find_by_order(m)), nd = abs(x - *ost.find_by_order(m+k));
            if (st < nd) hi = m;
            else if (st > nd) lo = m+1;
        }
        ans = max(abs(x - *ost.find_by_order(lo)), abs(*ost.find_by_order(lo+k-1) - x));
        av[idx] = ans;
    }
    for (auto& x : av) cout << x << ' ';
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
