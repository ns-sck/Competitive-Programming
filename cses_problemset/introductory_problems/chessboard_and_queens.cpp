#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<vector<int>>
#define mii map<int, int>
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
const int MOD = 1e9+7;
int ans = 0;
int allmask = (1 << 8) - 1;
char grid[8][8];

void rec(int mask, int row, int diag, int anti)
{
    if (mask == allmask) {
        ++ans;
        return;
    }
    for (int i = 0; i < 8; ++i) {
        int ndiag = row + (7-i);
        int nanti = row + i;
        if (((1 << i) & mask) == 0 && grid[row][i] != '*' 
        && !((1 << nanti) & anti) && !((1 << ndiag) & diag)) {
            rec(mask | (1 << i), row + 1, diag | (1 << ndiag), anti | (1 << nanti));
        }
    }
}

int32_t main() {

    ios;
    
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            cin >> grid[i][j];
        }
    }
    rec(0, 0, 0, 0);
    cout << ans << '\n';
    return 0;
}
