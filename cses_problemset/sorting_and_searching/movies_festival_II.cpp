#include <bits/stdc++.h>
using namespace std;

template<typename... T>
void dbg(T&&... args) { ((cout << args << " "), ...); cout << '\n';}

#define int long long

constexpr int MOD = 1e9+7;
constexpr int MAX = 2e5+1;

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    // cin >> t;
    while (tt--) {
        int N, K;
        cin >> N >> K;
        vector<pair<int, int>> mv;
        for (int i = 0; i < N; ++i) {
            int l, r;
            cin >> l >> r;
            mv.emplace_back(r, l);
        }  
        sort(mv.begin(), mv.end());
        int ans = 0, left = 0;
        multiset<int> s;
        for (int i = 0; i < N; ++i) {
            int start = mv[i].second;
            auto it = s.upper_bound(start);
            if (it == s.begin()) {
                if (s.size() < K) {
                    s.insert(mv[i].first);
                    ++ans;
                }
                continue;
            }
            s.erase(--it);
            s.insert(mv[i].first);
            ++ans;
        }
        cout << ans << '\n';
    }

    return 0;
}