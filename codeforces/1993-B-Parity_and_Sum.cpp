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


// 1 4 4 5 8 12 16 31 44 46 48 50
void solve() {
	int N; cin >> N;
    vi v(N);
    int o = 0, mxo = 0;
    priority_queue<int, vi, greater<>> pq;
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
        if ((v[i] & 1ll) == 1) {
            ++o;
            mxo = max(mxo, v[i]);
        } else pq.push(v[i]);
    }
    if (o == 0) {
        cout << 0 << '\n';
        return;
    }
    int ans = 0;
    while (pq.size() && pq.top() < mxo) {
        ++ans;
        mxo += pq.top();
        pq.pop();
    }
    if (pq.size()) ans += pq.size() + 1;
    cout << ans << '\n';
}

// 1 2 4 6 8 10

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
