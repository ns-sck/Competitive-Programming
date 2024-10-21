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
    string A; cin >> A;

    string S;
    for (int i = 0; i < N; ++i) {
        if (i < N - 1 && A[i] == '1' && A[i+1] == '1' ) {
            put("YES");
            return;
        }
        if (i && S.back() == A[i]) continue;
        S += A[i];
    }
    int a = 0;
    N = S.size();
    for (char c : S) if (c == '0') ++a;
    if (a > N / 2) put("NO");
    else put("YES");
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