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
	int N; cin >> N;
    vi v(N);
    for (auto& x : v) cin >> x;
    sort(all(v));
    int c = 1;
    for (int i = N-2; ~i; --i) {
        if (v[i] == v[i+1]) {
            ++c;
            continue;
        } else {
            if (c%2) {
                cout << "YES\n";
                return;
            }
            c = 1; 
        }
    }
    if (c%2) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
