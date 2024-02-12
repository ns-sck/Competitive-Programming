//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>
using namespace std;
int MOD = 1e9 + 7;
int ans = 0;
int n, k;
int rel[8][2] = {{1,2},{1,-2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,1},{-2,-1}};
int rec(vector<vector<vector<int>>>& dp, int move, int row1, int col1, int row2, int col2) {
    
    if (move > k) {
        return 0;
    }
    if(dp[row1][col1][move] != -1) {
        return dp[row1][col1][move];
    }
    int ans = 0;
    if (row1 == row2 && col1 == col2) {
        ans++;
    }
    for (int i = 0; i < 8; ++i) {
        int newRow = row1 + rel[i][0];
        int newCol = col1 + rel[i][1];
        if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n) {
            ans += rec(dp, move + 1, newRow, newCol, row2, col2);
            ans %= MOD;
        }
    }
    dp[row1][col1][move] = ans % MOD;
    return ans % MOD;
}

int main() {
// write your code here
    cin >> n >> k;
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k+1, -1)));
    int row1, col1, row2, col2;
    cin >> row1 >> col1 >> row2 >> col2;
    cout << rec(dp, 0, row1, col1, row2, col2);
	return 0;
}
