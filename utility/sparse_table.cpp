#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<vector<int>>
#define mii map<int, int>
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
const int MOD = 1e9+7;
const int _max = 2e5+1;
int arr[] = {24, 72, 18, 45, 30, 36, 54, 26};

void build(vii& table, int n)
{
    for (int i = 0; i < n; i++)
        table[i][0] = arr[i];

    for (int j = 1; j <= log2(n); j++)
        for (int i = 0; i <= n - (1 << j); i++)
            table[i][j] = __gcd(table[i][j - 1],
                    table[i + (1 << (j - 1))][j - 1]);
}

int query(vii& table, int L, int R)
{
    int j = (int)log2(R - L + 1);
    return __gcd(table[L][j], table[R - (1 << j) + 1][j]);
}
int32_t main() {

    ios;
    vii table(8, vi(8));
    build(table, 8);
    for (auto x : table) {
        for (auto y : x) {
            cout << y << ' ';
        }
        cout << '\n';
    }
    int l, r;
    cin >> l >> r; // inclusive
    cout << query(table, l, r);

    return 0;
}
