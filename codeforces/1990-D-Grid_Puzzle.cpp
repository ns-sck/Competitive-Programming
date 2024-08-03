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
    vi r(N), l(N, -1);
    for (int i = 0; i < N; ++i) {
        cin >> r[i];
        --r[i];
    }
    vector<bool> dup(N);
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if (dup[i]) {
            ++ans;
        } else if (l[i] >= r[i]) {
            continue;
        } else if (r[i] - l[i] > 2) {
            ++ans;
        } else {
            if (i < N-1) {
                if (l[i+1] < l[i]) {
                    if (r[i+1] > max(r[i], l[i]+2)) dup[i+1] = 1;
                    else r[i+1] = min(r[i+1], l[i]);
                }
                else l[i+1] = max(l[i]+2, r[i]);
            }
            ++ans;
        }
    }
    cout << ans << '\n';
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
