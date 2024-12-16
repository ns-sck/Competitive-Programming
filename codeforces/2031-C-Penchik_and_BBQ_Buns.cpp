#include <bits/stdc++.h>
using namespace std;

template<typename... T>
void dbg(T&&... args) { ((cout << args << " "), ...); cout << '\n';}

#define int long long

constexpr int MOD = 1e9+7;
constexpr int MAX = 2e5+1;

void solve() {
    int N; cin >> N;
    if (N < 27 && (N & 1)) {
        cout << -1 << '\n';
        return;
    }
    if (N & 1) {
        int c = 2; bool b = 0;
        for (int i = 1; i <= N; ++i) {
            if (i == 1 || i == 17 || i == 26) {
                cout << 1 << ' ';
                continue;
            }
            else if (i == 2 || i == 27) {
                cout << 1000000 << ' ';
                continue;
            }
            if (!b) {
                c++;
                cout << c << ' '; 
            } else {
                cout << c << ' ';
            }
            b ^= 1;
        }
    } else {
        int c = 1;
        for (int i = 1; i <= N; i += 2) {
            cout << c << ' ' << c++ << ' '; 
        }
    }
    cout << '\n';
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