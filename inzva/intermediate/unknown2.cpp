#include <iostream>
#include <vector>

#define int long long

using namespace std;

int f(int x) {
    int result = 0;
    while (x > 0) {
        result += x % 10;
        x /= 10;
    }
    return result;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int lo = 1, hi = n;
        int ans = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (mid - f(mid) >= k) {
                ans = mid;
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }
        if (ans != -1) {
            cout << n - ans + 1 << endl;
        }
        else {
            cout << 0 << endl;
        }
    }
}