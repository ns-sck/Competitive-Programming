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
    
    vi v(N);
    for (int& x : v) cin >> x;
    vector<bool> b(1000);
    for (int i = 0; i < min(K, 100ll); ++i) {
        for (int j = 0; j < N; ++j) {
            int c = 0;
            for (int k = 1; k < 1000; ++k) {
                if (b[k]) continue;
                ++c;
                if (c + j == v[j]) {
                    b[k] = 1;
                    break;
                }
            }
        }
    }
    for (int i = 1; i < 1000; ++i) {
        if (!b[i]) {
            cout << i << '\n';
            return;
        }
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