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
    vi v1(n), v2(n);
    for (int i = 0; i < n; ++i)
        cin >> v2[i];
    for (int i = 0; i < n; ++i) {
        cin >> v1[i];
    }
    map<int, int> m;
    priority_queue<int, vi, greater<>> pq;
    int ans = 0;
    int i = 0;
    for (i = 0; i < n; ++i) {

        if (v1[i] && v2[i]) {
            m[i+v2[i]-1] += v1[i];
            pq.push(i+v2[i]-1);
        }
        while (pq.size()) {
            int t = pq.top();
            if (t < i || m[t] <= 0) {
                pq.pop();
                continue;
            }
            ++ans;
            --m[t];
            break;
        }
    }
    while (pq.size()) {
        int t = pq.top();
        if (t < i || m[t] <= 0) {
            pq.pop();
            continue;
        }
        ++i;
        ++ans;
        --m[t];
    }
    cout << ans;
    return 0;
}
