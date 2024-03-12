#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define vii vector<vector<int>>
#define pii pair<int, int>
#define ar array

const int INF = 1e18;
const int MOD = 998244353;
const int _max = 2e5+1;

int32_t main() {
	
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    unordered_map<char, int> m;
    for (int i = n-1; ~i; --i) {
        if (s[i] == 'M') {
            m['M'] = (m['M'] + m['E']) % MOD;
        }
        if (s[i] == 'E') {
            m['E'] = (m['E'] + m['T']) % MOD;
        }
        if (s[i] == 'T') {
            m['T'] = (m['T'] + m['U']) % MOD;
        }
        if (s[i] == 'U') {
            ++m['U'];
        }
    }
    cout << m['M'];
    return 0;
}
