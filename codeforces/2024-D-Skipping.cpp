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

void solve() {
    int N; cin >> N;
    vi a(N), b(N);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x, --x;

    vi p = a;
    for (int i = 0; i < N - 1; ++i) {
        p[i+1] += p[i];
    }

    vi dis(N, INF);
    vector<bool> vis(N);

    priority_queue<pi, vpi, greater<>> pq;
    pq.push({0, 0});

    while (pq.size()) {
        auto [sk, i] = pq.top();
        pq.pop();

        if (dis[i] < sk) continue;
        dis[i] = sk;

        for (int j = i; ~j; --j) {
            if (sk + a[j] < dis[b[j]]) {
                pq.push({sk + a[j], b[j]});
                dis[b[j]] = sk + a[j];
            } else if (!vis[j]) {
                vis[j] = 1;
            } else break;
        } 
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        ans = max(ans, p[i] - dis[i]);
    }

    put(ans);

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