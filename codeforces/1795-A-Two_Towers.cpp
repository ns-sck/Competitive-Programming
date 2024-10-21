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
    int N, M;
    cin >> N >> M;
    string A, B;
    cin >> A >> B;
    
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < N - 1; ++i) {
        if (A[i] == A[i+1]) ++a;
    }
    for (int i = 0; i < M - 1; ++i) {
        if (B[i] == B[i+1]) ++b;
    }

    if (a + b > 1) c = 1;
    else if (a + b == 1) {
        if (A[N-1] == B[M-1]) c = 1;
    }

    if (c) put("NO");
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