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
    vi v(N), st;
    for (int& x : v) cin >> x;
    int ans = v.size();
    st = {v[0]};
    for (int i = 1; i < N-1; ++i) {
        if (v[i+1] > v[i] && v[i] > st.back()) { --ans; continue; }
        else if (v[i+1] < v[i] && v[i] < st.back()) { --ans; continue; }
        st.push_back(v[i]);
    }
    cout << N-ans;
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
