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
    // after sorting, no duplicates
    sort(s.begin(), s.end());
    vector<string> s1;
    do {
        s1.push_back(s);
    } while (next_permutation(s.begin(), s.end()));
    cout << s1.size() << '\n';
    for (string st : s1) {
        cout << st << '\n';
    }
    return 0;
}
