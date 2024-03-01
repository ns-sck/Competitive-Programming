#include <iostream>
#include <vector>
#include <set>
#include <string>

#define int long long
#define modulo 1000000007

using namespace std;

int fp(int a, int b) {
    if (b == 0) return 1;
    if (b % 2 == 1) return (a * fp(a, b - 1)) % modulo;
    int half = fp(a, b / 2);
    return (half * half) % modulo;
}

int hash_letter(char letter) {
    return letter - 'a' + 1;
}

int32_t main() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    set<int> hashes;
    int hash = 0;
    int p = 29;
    for (int i = 0; i < k; i++) {
        hash *= p;
        hash %= modulo;
        hash += hash_letter(s[i]);
        hash %= modulo;
    }
    hashes.insert(hash);
    // hash == s[0] * p ^ 2 + s[1] * p + s[2]
    for (int i = 0; i < n - k; i++) {
        // hash -= s[i] * p ^ (k - 1)
        hash -= hash_letter(s[i]) * fp(p, k - 1);
        hash %= modulo;
        hash += modulo;
        hash %= modulo;
        hash *= p;
        // hash == s[1] * p ^ 2 + s[2] * p
        hash += hash_letter(s[i + k]);
        hash %= modulo;
        hashes.insert(hash);
    }
    cout << hashes.size() << endl;
}