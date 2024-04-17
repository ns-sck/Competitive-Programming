#include <bits/stdc++.h>
#define ii pair<int,int>

using ll = long long;
using namespace std;

const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n = 1000;
    vector<int> spf(n+1, -1); // smallest prime factor
    for(int i = 2; i<=n; i++) {
        if(spf[i] == -1){
            for(int j = i; j<=n; j+=i) {
                if(spf[j] == -1){
                    spf[j] = i;
                }
            }
        }
    }

    for(int i = 2; i<=100; i++) {
        cout << i << " -> " <<  spf[i] << endl;
    }

    return 0;
}