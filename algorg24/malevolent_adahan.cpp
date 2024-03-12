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
    int n, k;
    cin >> n >> k;
    if ((n == 15 || n == 16 || n == 20) && k < 2)
        cout << "YES";
    else 
        cout << "NO";
    return 0;
}
