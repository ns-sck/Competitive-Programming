#include <bits/stdc++.h>
using namespace std;

template<typename... T>
void dbg(T&&... args) { ((cout << args << " "), ...); cout << '\n';}

#define int long long

constexpr int MOD = 1e9+7;
constexpr int MAX = 2e5+1;

void solve() {
    int N, A, B;
    cin >> N >> A >> B;
    vector<int> a(N);
    for (int& x : a) cin >> x;
    vector<int> prfx(N + 1);
    for (int i = 0; i < N; ++i)
        prfx[i+1] += prfx[i] + a[i];
    multiset<int> ms;
    int diff = B - A, l = -B, r = 1 - A;
    int ans = -(1ll << 60);
    for (int i = 0; i <= N; ++i) {
        if (ms.size()) ans = max(ans, prfx[i] - *ms.begin());
        if (l >= 0) {
            auto it = ms.find(prfx[l]);
            ms.erase(it);
        }
        if (r >= 0) ms.insert(prfx[r]);
        ++l; ++r;
    }
    cout << ans << '\n';
}


signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}