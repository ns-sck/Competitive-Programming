#include <bits/stdc++.h>
using namespace std;
#define int long long
set<int> s1;

void fll(int num1, int num2, int constant) {

    for (int i = 0; i <= num2; ++i) {
        for (int j = 0; j <= num1; ++j) {
            int sum = i * num1 + j * num2 + constant;
            s1.insert(sum);
        }
    }
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int32_t main() {

    int a, b, x;
    cin >> a >> b >> x;

    int up = 3 * (a * b);

    s1.insert(a);
    s1.insert(b);
    fll(a, b, a+b);
    int gcdd = gcd(a, b);
    vector<int> v;

    for (auto y : s1) {
        v.push_back(y);
    }

    auto it = upper_bound(v.begin(), v.end(), (a * b));
    int where = distance(v.begin(), it);
    int ans = 0;
    if (where < x) {
        ans = (x - where) * gcdd + v[where];
    } else {
        ans = v[x];
    }
    cout << ans;
    return 0;
}
