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

vector<string> v(501);
void solve() {
    int N; cin >> N;
    put(v[N]);
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    v[1] = "-1";
    v[2] = "66";
    v[3] = "-1";
    v[4] = "3366";
    v[5] = "36366";
    v[6] = "333366";
    v[7] = "3336366";
    for (int i = 8; i <= 500; ++i) {
        string s = "33";
        s += v[i-2];
        v[i] = s;
    }

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}