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
    string S; cin >> S;
    int N = S.size();

    vi a(10);
    for (int i = 0; i < N; ++i) {
        ++a[S[i] - '0'];
    }

    int mx = 0;
    for (int i = 0; i < 10; ++i) mx = max(mx, a[i]);

    int ans = 0;
    if (mx == N) {
        put(-1);
        return;
    }
    if (mx <= N / 2) {
        put(N);
        return;
    } else {
        int b = N - mx;
        ans += 2 * (b - 1);
        mx -= (b - 1);
        ans += mx * 2 - 1 + (mx & 1);
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