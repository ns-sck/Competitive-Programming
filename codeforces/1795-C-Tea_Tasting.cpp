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
    vi a(N), b(N), prfx(N);

    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;
    prfx[0] = b[0];
    for (int i = 1; i < N; ++i) {
        prfx[i] = prfx[i-1] + b[i];
    }

    vi st(N), end(N), c(N);

    int l = 0;
    for (int i = 0; i < N; ++i) {
        int x = a[i];
        x += l;
        auto it = lower_bound(all(prfx), x);
        if (it == prfx.end()) {
            ++st[i];
        } else {
            int j = it - prfx.begin();
            if (prfx[j] == x) {
                ++st[i];
                ++end[j];
            } else if (j > i) {
                ++st[i];
                ++end[j-1];
                int rm = x - prfx[j-1];
                c[j] += rm;
            } else {
                c[i] += a[i];
            }
        }
        l += b[i];
    }

    vi ans(N);
    int x = 0;
    for (int i = 0; i < N; ++i) {
        x += st[i];
        ans[i] += x * b[i] + c[i];
        x -= end[i];
        cout << ans[i] << " \n"[i == N - 1];
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