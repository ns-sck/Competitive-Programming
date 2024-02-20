#include <bits/stdc++.h>
#define int long long
using namespace std;
int ans = LLONG_MAX;
int k;
bool findd(int left, int count, vector<int>& v)
{   
    if (left > v.size() - 3) {
        return false;
        // 1 2 3 4 5 6 7 8 9
    }
    auto it = upper_bound(v.begin(), v.end(), v[left] + (2 * k));
    if (it == v.end()) {
        ans = min(ans, count);
        return true;
    }
    --it;
    int dist = distance(v.begin(), it) - left;
    if (dist < 2) {
        return false;
    }
    bool b = false;
    
    while (dist >= 2) {
        b = findd(left + dist + 1, count + 1, v);
        if (b) {
            return true;
        }
        --dist;
    }
    return false;
}

int32_t main() {
// write your code here
    int n;
    cin >> n >> k;
    if (n <= 2) {
        cout << -1;
        return 0;
    }
    vector<int> v(n, 0);
    
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    if (findd(0, 1, v)) {
        cout << ans << '\n';
    } else {
        cout << -1 << '\n';
    }

    return 0;
}
