#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define vii vector<vector<int>>
#define pii pair<int, int>
#define ar array

const int INF = 1e18;
const int MOD = 1e9+7;
const int _max = 2e5+1;

int32_t main() {
	
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
        
    map<string, int> ends;
    map<string, int> ends2;
    map<string, int> starts;
    map<string, int> starts2;
    int c = 0;
    bool b = false;
    for (int i = 0; i < n; ++i) {
        string s = v[i].substr(0,3);
        string e = v[i].substr(1,3);
        if ((b && ends2[s] == 0) || (b && starts2[e] == 0)) {
            cout << "NO\n";
            return 0;
        }
        if (starts.count(e) && starts[e] > 0) {
            starts[e]--;
            c--;
        } else {
            c++;
            ends[e]++;
        }
        if (ends.count(s) && ends[s] > 0) {
            ends[s]--;
            c--;
        } else {
            c++;
            starts[s]++;
        }
        ends2[e]++;
        starts2[s]++;
        if (c == 0) {
            b = true;
        }
    }
    int s1 = 0;
    int e1 = 0;

    for (auto p : starts) {
        s1 += p.second;
    }
    for (auto p : ends) {
        e1 += p.second;
    }
    if (e1 == 1 && s1 == 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}
