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
    
    int u = -1, l = INF;
    for (int i = 1; i <= N; ++i) {
        int a = N, b = i;
        bool bl = 1;
        for (int j = 2; j < K; ++j) {
            int c = a - b;
            a = b;
            b = c;
            if (a < b || a < 0 || b < 0) {
                bl = 0;
                break;
            }
        }
        if (bl) u = max(u, i), l = min(l, i);
    }
    if (u == -1 || l == -1 || u < l) cout << 0 << '\n';
    else cout << (u - l + 1) << '\n';

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