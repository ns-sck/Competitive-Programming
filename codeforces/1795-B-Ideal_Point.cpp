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
    int N, K;
    cin >> N >> K;

    vi st(51), end(51);
    for (int i = 0; i < N; ++i) {
        int l, r;
        cin >> l >> r;
        if (K >= l && K <= r) ++st[l], ++end[r];
    }

    vi a(51);

    int c = 0;
    for (int i = 0; i < 51; ++i) {
        c += st[i];
        a[i] = c;
        c -= end[i];
    }

    int x = a[K];
    for (int i = 0; i < 51; ++i) {
        if (i == K) continue;
        if (a[i] >= a[K]) {
            put("NO");
            return;
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