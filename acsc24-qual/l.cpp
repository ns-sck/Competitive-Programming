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

void kmp(const string& s, int l, int* p, int* p2) {
    int n = s.size();
    
    for (int i = 1; i < n; ++i) {
        int j = p[i-1];
        while (j > 0 && s[i] != s[j])
            j = p[j-1];

        if (s[i] == s[j])
            j++;

        p[i] = j;
        if (i > l && i-p[i] >= l) break;
    }

    for (int i = l+1; i < n; ++i) {
        int j = p2[i-1];
        while (j > 0 && s[i] != s[j])
            j = p2[j-1];

        if (s[i] == s[j])
            j++;

        p2[i] = j;
    }
}

void solve() {
    int N, M, P, D;
    cin >> N >> M >> P >> D;
    string s; cin >> s;

    while (M--) {
        int l, r;
        cin >> l >> r;
        int len = r-l+1, st = len+l+1, mx = 0, ans = -INF;
        string ss = s.substr(l, r-l+1) + '#' + s;
        int n = ss.size();
        int p[n] = {};
        int p2[n] = {};
        kmp(ss, l+len+1, p, p2);
        bool b = 0;

        for (int i = len+1; i < N+len+1; ++i) {
            int st = i-p[i]-len;
            if (st == l) continue;
            if (p[i] > mx) {
                b = 1;
                mx = p[i];
                ans = (P*mx - D*abs(l-st));
            } else if (p[i] == mx && mx) {
                ans = max(ans, P*mx - D*abs(l-st));
            }
        }
        for (int i = l+len+2; i < N+len+1; ++i) {
            int st = i-p2[i]-len;
            if (p2[i] > mx) {
                b = 1;
                mx = p2[i];
                ans = (P*mx - D*abs(l-st));
            } else if (p2[i] == mx && mx) {
                ans = max(ans, P*mx - D*abs(l-st));
            }
        }
        if (ans < 0 || !b) cout << ":(\n";
        else cout << ans << '\n';
    }
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
