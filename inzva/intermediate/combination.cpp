#include <iostream>

#define int long long
#define modulo 1000000007

using namespace std;

int poww(int a, int b) {
    if (b == 0) return 1;
    if (b % 2 == 1) return (a * poww(a, b - 1)) % modulo;
    int half = poww(a, b / 2);
    return (half * half) % modulo;
}

int factorial(int x) {
    int result = 1;
    for (int i = 1; i <= x; i++) {
        result *= i;
        result %= modulo;
    }
    return result;
}

int32_t main() {
    int a, b;
    cin >> a >> b;
    // a! * (b! * (a-b)! % mod) ^ mod - 2
    cout << factorial(a) * poww((factorial(b) * factorial(a-b)) % modulo, modulo - 2) % modulo << endl;
}