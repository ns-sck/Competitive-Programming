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
    int M, P;
    cin >> M >> P;

    vi a(M), b(P);

    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;

    sort(all(a));
    sort(all(b));

    int i = 0, j = 0;

    while (i < M && j < P) {
        if (b[j] >= a[i]) ++i, ++j;
        else ++j;
    }
    
    cout << i << '\n';
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}