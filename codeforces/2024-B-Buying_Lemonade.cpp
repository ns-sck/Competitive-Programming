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
    sort(all(v));

    vi v2 = v;
    for (int i = 0; i < N - 1; ++i) {
        v2[i+1] += v2[i];
    }

    int lo = 0, hi = N;
    int t = v2[N-1];
    int ans = N - 1;
    while (lo <= hi) {
        int mi = (lo + hi) >> 1;
        int x = v[mi];
        int r = N - mi;
        int s = r * x + (mi ? v2[mi-1] : 0);
        if (s >= K) {
            ans = mi;
            hi = mi - 1;
        } else if (s < K) {
            lo = mi + 1;
        } 
    }
    
    put(K + ans);
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