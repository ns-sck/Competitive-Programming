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
unordered_map<int, vector<pii>> upp;
unordered_map<int, vector<pii>> dwn;
int n;

int rec(int idx, bool up, int diff, vi& v, int step) {

    if (up && upp[idx].size()) {
        for (auto p : upp[idx]) {
            if (p.first == diff) {
                return p.second + step;
            }
        }
    }
    if (!up && dwn[idx].size()) {
        for (auto p : dwn[idx]) {
            if (p.first == diff) {
                return p.second + step;
            }
        }
    }
    int ans = step;
    for (int i = idx+1; i < n; ++i) {
        if (up && v[i] > v[idx] && v[i] - v[idx] < diff) {
            ans = max(ans, rec(i, !up, v[i] - v[idx], v, step+1));
        } else if (!up && v[idx] > v[i] && v[idx] - v[i] < diff) {
            ans = max(ans, rec(i, !up, v[idx] - v[i], v, step+1));
        }
    }
    if (up)
        upp[idx].push_back({diff, ans-step});
    else 
        dwn[idx].push_back({diff, ans-step});
        
    return ans;
}

int32_t main() {
	
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    vi v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, rec(i, 1, 1e18, v, 1));
        ans = max(ans, rec(i, 0, 1e18, v, 1));
    }
    if (ans > 2)    
        cout << ans << '\n';
    else 
        cout << 0 << '\n';
    return 0;
}
