#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<vector<int>>
#define mii map<int, int>
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
const int MOD = 1e9+7;

int32_t main() {

    ios;
    string s; cin >> s;
    int count = 0, ans = 1;
    char last = 'E';
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == last)
            ++count;
        else {
            count = 1;
        }
        last = s[i];
        ans = max(ans, count);
    }
    cout << ans;
    return 0;
}
