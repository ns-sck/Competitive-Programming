#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,
             tree_order_statistics_node_update>;
template<typename... T>
void dbg(T&&... args) { ((cout << args << " "), ...); cout << '\n';}

#define int long long

constexpr int MOD = 1e9+7;
constexpr int MAX = 2e5+1;


void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for (int& x : a) cin >> x;
    oset<pair<int, int>> os;
    for (int i = 0; i < K; ++i) os.insert({a[i], i});
    int mid = os.find_by_order((K - 1) / 2)->first, low = 0, up = 0;
    vector<int> midarr(N);
    map<int, int> mp;
    int sm = 0, bg = 0;
    int st = 0, bt = 0;
    for (int i = 0; i < K; ++i) {
        if (a[i] <= mid) ++sm, st += a[i];
        else ++bg, bt += a[i];
    }
    for (int i = K - 1; i < N; ++i) {
        midarr[i] = mid;
        os.erase(os.lower_bound({a[i - K + 1], 0}));
        os.insert({a[i + 1], i});
        mid = os.find_by_order((K - 1) / 2)->first;
    }
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