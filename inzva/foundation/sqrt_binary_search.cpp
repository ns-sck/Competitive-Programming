#include <bits/stdc++.h>
using namespace std;


const double epsilon_rate = 1e-9;
double sqrt_with_bs(double x) {
    double l = 0, r = x;
    while(r - l > epsilon_rate) {
        double m = (l + r) / 2;
        if(m * m > x) r = m;
        else l = m;
    }
    return l;
}

int main() {
    double x;
    cin >> x;
    cout << sqrt_with_bs(x);
}