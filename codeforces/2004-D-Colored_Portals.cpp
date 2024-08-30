#include <bits/stdc++.h>
using namespace std;

template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...); cout << '\n';}

#define int long long
#define ll long long
#define pi pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpi vector<pi>
#define pb push_back
#define ar array
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const ll MOD = 1e9+7;
const ll INF = 1e18;
const ll MAX = 2e5+1;

int f(char c) {
    if (c == 'B') return 0;
    if (c == 'G') return 1;
    if (c == 'R') return 2;
    if (c == 'Y') return 3;
}

int f2(int x, int y) {
    if (x == 0 && y == 1) return 0;
    if (x == 0 && y == 2) return 1;
    if (x == 0 && y == 3) return 2;
    if (x == 1 && y == 2) return 3;
    if (x == 1 && y == 3) return 4;
    if (x == 2 && y == 3) return 5;
}

void solve() {
    int N, Q;
    cin >> N >> Q;
    vpi clr(N+1);
    vector<set<int>> v(6);
    for (int i = 1; i <= N; ++i) {
        char a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        clr[i].first = f(a);
        clr[i].second = f(b);
        int idx = f2(f(a), f(b));
        v[idx].insert(i);
    }

    auto ch = [&](int u, int v) {
        return clr[u].first == clr[v].first || clr[u].first == clr[v].second || clr[u].second == clr[v].first || clr[u].second == clr[v].second;
    };

    while (Q--) {
        int u, x;
        cin >> u >> x;
        if (u > x) swap(u, x);
        if (u == x) {
            cout << 0 << '\n';
            continue;
        }
        if (ch(u, x)) {
            cout << x - u << '\n';
            continue;
        }
        int a1 = f2(clr[u].first, clr[u].second), a2 = f2(clr[x].first, clr[x].second);
        int ans = INF;

        for (int i = 0; i <= 5; ++i) {
            if (i == a1 || i == a2) continue;
            auto it = v[i].upper_bound(u);
            if (it != v[i].end()) {
                ans = min(ans, abs((*it) - u) + abs((*it) - x));
            }
            auto it2 = v[i].lower_bound(u);

            if (it2 != v[i].begin()) {
                --it2;
                int aa = *it2;
                ans = min(ans, abs((aa) - u) + abs((aa) - x));
            }
        }
        
        if (ans == INF) cout << -1 << '\n';
        else cout << ans << '\n';
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
