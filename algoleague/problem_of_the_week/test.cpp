#include <bits/stdc++.h>
using namespace std;

int main() {
    mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<> dis(40, 60);
    uniform_int_distribution<> dis2(0, 9);
    int x = dis(gen);
    cout << 1 << '\n' << x << ' ' << x << '\n';
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < x; ++j) {
            int z = rand() % 2;
            int y = dis2(gen);
            if (z)
                cout << y << ' ';
            else cout << 0 << ' ';
        }
        cout << '\n';
    }

    return 0;
}
