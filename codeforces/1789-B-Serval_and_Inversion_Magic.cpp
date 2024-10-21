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
    int i = 0, j = N - 1;
    vector<bool> b(N);

    while (i < N / 2) {
        if (S[i] == S[j]) b[i] = 1;
        ++i, --j;
    }
    i = 0, j = N - 1;
    while (i < N / 2 && b[i]) ++i;
    while (i < N / 2 && !b[i]) {
        if (S[i] == '1') S[i] = '0';
        else S[i] = '1';
        ++i;
    }
    i = 0, j = N-1;
    while (i < j) {
        if (S[i] == S[j]) b[i] = b[j] = 1;
        else {
            put("NO");
            return;
        }
        ++i, --j;
    }
    put("YES");
    
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