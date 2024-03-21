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
    
    int n, m;
    cin >> n >> m;
    vi v(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
    }
    string s;
    cin >> s;
    // 1 1 1 1 1 1
    int md = (n+1)/2;
    for (int i = 0; i < m; ++i) {
        if (s[i] == 'r') {
            int r = (n-md+1)/2;
            md += r;
        } else {
            int l = (md)/2;
            md -= l;
        }
    }
    cout << v[md];
    return 0;
}
