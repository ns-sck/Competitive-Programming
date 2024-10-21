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
    int N, M, K;
    cin >> N >> M >> K;

    vi a(N), b(M);

    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;

    sort(all(a));
    sort(all(b));

    int i = 0;
    set<int> sa, sb;
    while (i < N && a[i] <= K) {
        sa.insert(a[i++]);
    }

    i = 0;
    while (i < M && b[i] <= K) {
        sb.insert(b[i++]);
    }

    if (sa.size() < K / 2 || sb.size() < K / 2) {
        put("NO");
        return;
    }

    for (int i = 1; i <= K; ++i) {
        auto it = sa.find(i);
        if (it == sa.end()) {
            auto it = sb.find(i);
            if (it == sb.end()) {
                put("NO");
                return;
            }
        }
    }

    put("YES");
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