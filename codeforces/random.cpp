#include <bits/stdc++.h>
using namespace std;

int main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    vector<string> v = {"10at", "abd", "ns", "boz", "saro", "ert"};
    uniform_int_distribution<> dis(0, 1e9); 

    for (int i = 0; i < 3; ++i) {
        int x = dis(rng) % (6 - i);
        cout << v[x] << '\n';
        v.erase(find(v.begin(), v.end(), v[x]));
    }
    cout << '\n';
    for (auto s : v) cout << s << '\n';

    return 0;
}
