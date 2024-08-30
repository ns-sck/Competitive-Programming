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
    vi v(N);
    for (int &x : v) cin >> x;
    if (N > 2) {
        cout << "NO\n";
        return;
    }
    
    if (N == 2 && abs(v[0] - v[1]) == 1) {
        cout << "NO\n";
    } else cout << "YES\n";
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
