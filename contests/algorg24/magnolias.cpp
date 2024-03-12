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
    cin >> n;
    set<int> s;
    map<int, int> st;
    map<int, int> end;
    int m = n;

    while (m--) {
        int a, b;
        cin >> a >> b;
        st[a]++;
        end[b]++;
        s.insert(a); s.insert(b);
    }
    int i = 0;
    int sz = s.size();
    vi v(sz);
    vi v2(sz);
    for (auto x : s) {
        v[i++] = x;
    }
    int _fill = 0;
    i = 1;
    int fill = 1;
    v2[0] = fill;
    for (i = 1; i < sz; ++i) {
        if (st[v[i]] > 0)
            fill += st[v[i]];
        _fill = max(fill, _fill);
        v2[i] = fill;
        if (end[v[i]] > 0)
            fill -= end[v[i]];
    }
    unordered_map<int, int> mp;
    int ans = 0;
    for (int j = sz-1; j; --j) {
        if (v2[j-1] == _fill && v2[j] == _fill && st[v[j]] < 1 && end[v[j-1]] < 1) {
            ans += v[j] - v[j-1] + 1;
            mp[v[j-1]]++;
            if (mp[v[j]] > 0)
                --ans;
        }
        else if (v2[j] == _fill && end[v[j]] > 0) {
            ++ans;
        }
    }
    if (v2[0] == _fill && end[v[0]] > 0)
        ++ans;
    cout << ans;
    return 0;
}
