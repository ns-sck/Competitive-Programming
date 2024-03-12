#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define vii vector<vector<int>>
#define pii pair<int, int>
#define ar array

const int INF = 1e18;
const int MOD = 1e9+7;
const int _max = 2e5+1;

int32_t main() {
	
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    map<char, int> m;
    int ans = INT_MAX;
    int j = 0;

    for (int i = 0; i < n; ++i) {
        while (j < n && (m['R'] < 1 || m['O'] < 2 || m['B'] < 1 || m['T'] < 1)) {
            m[s[j++]]++;
        }
        if (m['R'] > 0 && m['O'] > 1 && m['B'] > 0 && m['T'] > 0) {
            ans = min(ans, j-i);
        }
        m[s[i]]--;
    }
    if (ans == INT_MAX)
        cout << -1;
    else
        cout << ans;
    return 0;
}
