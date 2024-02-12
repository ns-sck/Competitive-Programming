//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
// write your code here
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans++;
        int a = 1;
        int last = v[i];
        while (true) {
            if (i - a >= 0 && v[i - a] < last) {
                ans++;
                last = v[i - a];
            } else {
                break;
            }
            if (i + a < n && v[i + a] < last) {
                ans++;
                last = v[i + a];
            } else {
                break;
            }
            a++;
        }
    }
    cout << ans;
	return 0;
}
