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

int N, M;
vvi g;

// 0 -> left
// 1 -> up
// 2 -> right
// 3 -> down

int dfs(int i, int j, int dig, int layer, int last) {
    if (i == -1 || i == N || j == -1 || j == M) return 0;
    int x = min({i, j, N - 1 - i, M - 1 - j});
    if (x != layer) return 0;
    if ((dig == 0 && g[i][j] != 1) || 
        (dig == 1 && g[i][j] != 5) || 
        (dig == 2 && g[i][j] != 4) || 
        (dig == 3 && g[i][j] != 3)) return 0;
    if (dig == 3) return 1;

    int result = 0;
    if (last == 0) {
        if (j - 1 < layer) result += dfs(i - 1, j, dig + 1, layer, 1);
        else result += dfs(i, j - 1, dig + 1, layer, last);
    } else if (last == 1) {
        if (i - 1 < layer) result += dfs(i, j + 1, dig + 1, layer, 2);
        else result += dfs(i - 1, j, dig + 1, layer, last);
    } else if (last == 2) {
        if (M - 1 - (j + 1) < layer) result += dfs(i + 1, j, dig + 1, layer, 3);
        else result += dfs(i, j + 1, dig + 1, layer, last);
    } else if (last == 3) {
        if (N - 1 - (i + 1) < layer) result += dfs(i, j - 1, dig + 1, layer, 0);
        else result += dfs(i + 1, j, dig + 1, layer, last);
    }
    return result;
}

void solve() {
    cin >> N >> M;
    vvi b(N, vi(M));
    g = b;
    for (int i = 0; i < N; ++i) {
        string S; cin >> S;
        for (int j = 0; j < M; ++j) g[i][j] = S[j] - '0';
    }
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (g[i][j] == 1) {
                int layer = min({i, j, N - 1 - i, M - 1 - j});
                if (i < (N - 1 - i)) ans += dfs(i, j + 1, 1, layer, 2);
                if (i > (N - 1 - i)) ans += dfs(i, j - 1, 1, layer, 0);
                if (j < (M - 1 - j)) ans += dfs(i - 1, j, 1, layer, 1);
                if (j > (M - 1 - j)) ans += dfs(i + 1, j, 1, layer, 3);
            }   
        }
    }
    put(ans);
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
