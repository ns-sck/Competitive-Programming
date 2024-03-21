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

vi pr;
vector<bool> v(5e5, true);

void sieve() {
    
    v[0] = false; v[1] = false;
    for (int i = 2; i < 5e5; ++i) {
        if (!v[i])
            continue;
        for (int j = 2*i; j < 5e5; j += i) {
            v[j] = false;
        }
    }
    for (int i = 2; i < 5e5; ++i) {
        if (v[i])
            pr.push_back(i);
    }
}

int32_t main() {
	
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    sieve();
    while (n--) {
        int q;
        cin >> q;
        int ans = 0;
        for (auto x : pr) {
            if (x > q/2)
                break;
            if (v[q-x])
                ++ans;
        }
        cout << ans << '\n';
    }
    
    return 0;
}
