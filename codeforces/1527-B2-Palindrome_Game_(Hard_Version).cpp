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
    string S; cin >> S;

    int x = 0, y = 0;
    for (int i = 0; i < N; ++i) x += S[i] == '0', y += S[i] != S[N-i-1];
    y >>= 1;
    if (!y) {
        if (x & 1) {
            if (x == 1) put("BOB");
            else put("ALICE");
        } else {
            put("BOB");
        }
    } else if (y > 2) {
        put("ALICE");
    } else if (y == 2) {
        put("ALICE");
    } else {
        if (x & 1) {
            put("ALICE");
        } else {
            if (x == 2) put("DRAW");
            else put("ALICE");
        }
    }

    // 1 1 0 0 0 1 1
    // 1 1 0 0 0 1
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