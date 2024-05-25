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
const ld EPS = 1e-9; 

void solve() {
    string s; cin >> s;
    int i = 0, sz = s.size(), ans = 1;
    while (i < sz && s[i] == '0') ++i;
    while (i < sz && s[i] == '1') ++i;
    if (s[0] != '0' && i < sz) {
        while (i < sz && s[i] == '0') ++i;
        while (i < sz && s[i] == '1') ++i;
        ans = 2;
    }
    char last = '1';    
    for (; i < sz;) {
        while (i < sz && s[i] != last) ++i;
        ++ans;
        last = (1 - (last-'0')) + '0';
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
