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
    unordered_map<int, int> mp;
    vi a(N), b(N);
    for (int i = 0; i < N; ++i) cin >> a[i], ++mp[a[i]];
    bool bl = 0;
    for (int i = 0; i < N; ++i) {
        cin >> b[i];
        if (!mp[b[i]]) {
            bl = 1;
        }
        mp[b[i]] = i;
    }
    if (bl) {
        cout << "NO\n";
        return;
    }
    int c = 0;
    for (int i = 0; i < N; ++i) {
        if (a[i] == b[i]) continue;
        c += (mp[a[i]]-i)*2-1;
        mp[b[i]] = mp[a[i]];
        swap(b[i], b[mp[a[i]]]);
    }
    if (c%2) cout << "NO\n";
    else cout << "YES\n";
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
