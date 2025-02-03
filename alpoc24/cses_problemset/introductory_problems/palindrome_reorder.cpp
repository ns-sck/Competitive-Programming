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

    vector<char> v1;
    vector<char> v2;
    unordered_map<char, int> m;
    for (int i = 0; i < s.length(); ++i) {
        m[s[i]]++;
    }
    bool b = false;
    char mid;
    int num = 0;
    for (auto p : m) {
        char c = p.first;
        int n = p.second;
        if (b && n % 2) {
            cout << "NO SOLUTION\n";
            return 0;
        }
        if (n % 2) {
            mid = c;
            num = n;
            b = true;
            continue;
        }
        for (int i = 0; i < n / 2; ++i) {
            v1.push_back(c);
            v2.push_back(c);
        }
    }
    for (int i = 0; i < (s.length() - num) / 2; ++i) {
        cout << v1[i];
    }
    for (int i = 0; i < num; ++i) {
        cout << mid;
    }
    for (int i = (s.length() - num) / 2 - 1; i >= 0; --i) {
        cout << v1[i];
    }
    return 0;
}
