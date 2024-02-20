//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>
using namespace std;

int main() {
// write your code here
    int m, n, k, x, y;
    cin >> m >> n >> k >> x >> y;
    
    int ans = 0;
    
    while (k--) {
        int x1, y1;
        cin >> x1 >> y1;
        
        if ((x1 - x) % 2) {
            int diff = abs(y1 - y);
            if (diff <= abs(x1 - x)) {
                ++ans;
                continue;
            }
        }
        if ((y1 - y) % 2) {
            int diff = abs(x1 - x);
            if (diff <= abs(y1 - y))
                ++ans;
        }
    }
    cout << ans << '\n';
	return 0;
}
