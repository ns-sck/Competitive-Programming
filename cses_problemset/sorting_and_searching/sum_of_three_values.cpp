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

void solve() {
    int N, X;
    cin >> N >> X;
    
    vi v(N), a, b(N);
    for (int& x : v) cin >> x;

    iota(all(b), 0);
    sort(all(b),[&](int i, int j){
        return v[i] < v[j];
    });
    sort(all(v));

    for (int i = N-1; i >= 2; --i) a.pb(v[i]);

    for (int i = 1; i < N - 1; ++i) {
        for (int j = 0; j < i; ++j) {
            int t = X - v[i] - v[j];
            if (t <= 0) break;
            auto it = lower_bound(a.begin(), a.end(), t, greater<int>());
            if (it != a.end() && *it == t) {
                put(b[j] + 1, b[i] + 1, b[a.end() - it + i] + 1);
                return;
            }
        }
        a.pop_back();
    }

    cout << "IMPOSSIBLE";
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
