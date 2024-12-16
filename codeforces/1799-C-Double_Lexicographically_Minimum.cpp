#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    string S;
    cin >> S;
    map<char, int> mp;
    for (char& c : S) {
        ++mp[c];
    }
    string A, B;
    char last = '!';
    bool differ = 0;
    int left = S.size();
    for (auto [c, x] : mp) {
        left -= x;
        if (last == '!') {
            while (x >= 2) {
                A += c;
                B += c;
                x -= 2;
            }
            if (x == 1) last = c;
            if (left == 0 && x) {
                A += c;
            }
        } else {
            if (left) {
                B += last;
                auto it = mp.find(c);
                while (it != mp.end()) {
                    for (int i = 0; i < it->second; ++i) {
                        A += it->first;
                    }
                    ++it;
                }
                break;
            } else {
                while (x >= 2) {
                    A += c;
                    B += c;
                    x -= 2;
                }
                if (x) A += c;
                B += last;
            }
        }
    }
    reverse(B.begin(), B.end());
    A += B;
    cout << A << '\n';
}

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}