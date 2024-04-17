#include <bits/stdc++.h>
using namespace std;
int main () {

    int n, m;
    cin >> n >> m;
    vector<vector<int>> v;
    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        v.push_back({a,b,w});
    }

    vector<int> d(n+1, 1e9);
    vector<int> pr(n+1, -1);
    d[1] = 0;
    int x;
    for (int i = 0; i < n; ++i) {
        x = -1;
        bool f = false;
        for (auto p : v) {
            if (d[p[0]] < 1e9) {
                if (d[p[1]] > d[p[0]] + p[2]) {
                    d[p[1]] = max(INT_MIN, d[p[0]] + p[2]);
                    pr[p[1]] = p[0];
                    x = p[1];
                    f = true;
                }
            }
        }
        if (!f)
            break;
    }
    // if (x != -1)
        // cout << "negative cycle";
    for (int i = 1; i <= n; ++i) {
        cout << "dist = " << d[i] << '\n';
        vector<int> pth;
        for (int j = i; j != -1; j = pr[j]) {
            pth.push_back(j);
        }
        reverse(pth.begin(), pth.end());
        for (auto x : pth) {
            cout << x << ' ';
        }
        cout << '\n';
    }

    return 0;
}