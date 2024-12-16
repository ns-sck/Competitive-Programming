#include <bits/stdc++.h>
using namespace std;

template<typename... T>
void dbg(T&&... args) { ((cout << args << " "), ...); cout << '\n';}

#define int long long

constexpr int MOD = 1e9+7;
constexpr int MAX = 2e5+1;

void solve() {
    int N; cin >> N;
    vector<int> a(N);
    for (int& x : a) cin >> x;
    vector<vector<int>> ans = {a};
    for(;;) {
        map<int, int> mp;
        vector<int> b;
        for (int i = 0; i < N; ++i) {
            ++mp[a[i]];
        }
        bool bl = 0;
        int j = ans.size() - 1;
        for (int i = 0; i < N; ++i) {
            a[i] = mp[a[i]];
            if (a[i] != ans[j][i]) bl = 1;
        }
        ans.emplace_back(a);
        if (!bl) break;
    }
    int Q; cin >> Q;
    while (Q--) {
        int s, i;
        cin >> i >> s;
        --i;
        s = min(s, (long long) ans.size() - 1);
        cout << ans[s][i] << '\n';
    }
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}