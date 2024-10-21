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
    int mn = 1;
    for (int i = 0; i < K; ++i) {
        if (i & 1) {
            int d = (N - 1 - i) / K + 1;
            int st = mn + d - 1;
            mn = st + 1;
            for (int j = i; j < N; j += K) {
                v[j] = st--;
            }
            continue;
        } 
        for (int j = i; j < N; j += K) {
            v[j] = mn++;
        }
    }

    for (int i = 0; i < N; ++i) 
        cout << v[i] << " \n"[i == N-1];
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