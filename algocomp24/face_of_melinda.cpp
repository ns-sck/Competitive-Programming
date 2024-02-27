#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<vector<int>>
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
const int MOD = 1e9+7;

int32_t main() {

    ios;
    int t; cin >> t;
    
    while (t--) {
        unordered_map<string, int> m;
        unordered_map<string, int> m2;
        string s; cin >> s;
        int len = s.length();
        vi v(len, 0);
        vi v2(len, 0);
        for (int i = len-1; i >= 0; --i) {
            if (s[i] == 'a') {
                m["artisthine"] = (m["artisthine"] + m["rtisthine"]) % MOD;
                v[i] = m["rtisthine"] % MOD;
            }
            if (s[i] == 'm') {
                m["myheartisthine"] = (m["myheartisthine"] + m["yheartisthine"]) % MOD;
                v[i] = m["yheartisthine"] % MOD;
            }
            if (s[i] == 'y') {
                m["yheartisthine"] = (m["yheartisthine"] + m["heartisthine"]) % MOD;
                v[i] = m["heartisthine"] % MOD;
            }
            if (s[i] == 'h') {
                m["heartisthine"] = (m["heartisthine"] + m["eartisthine"]) % MOD;
                m["hine"] = (m["hine"] + m["ine"]) % MOD;
                v[i] = m["eartisthine"] % MOD;
                v2[i] = m["ine"] % MOD;
            }
            if (s[i] == 'e') {
                m["eartisthine"] = (m["eartisthine"] + m["artisthine"]) % MOD;
                m["e"] = (m["e"] + 1) % MOD;
                v[i] = m["artisthine"] % MOD;
            }
            if (s[i] == 'r') {
                m["rtisthine"] = (m["rtisthine"] + m["tisthine"]) % MOD;
                v[i] = m["tisthine"] % MOD;
            }
            if (s[i] == 't') {
                m["tisthine"] = (m["tisthine"] + m["isthine"]) % MOD;
                m["thine"] = (m["thine"] + m["hine"]) % MOD;
                v[i] = m["isthine"] % MOD;
                v2[i] = m["hine"] % MOD;
            }
            if (s[i] == 'i') {
                m["isthine"] = (m["isthine"] + m["sthine"]) % MOD;
                m["ine"] = (m["ine"] + m["ne"]) % MOD;
                v[i] = m["sthine"] % MOD;
                v2[i] = m["ne"] % MOD;
            }
            if (s[i] == 's') {
                m["sthine"] = (m["sthine"] + m["thine"]) % MOD;
                v[i] = m["thine"] % MOD;
            }
            if (s[i] == 'n') {
                m["ne"] = (m["ne"] + m["e"]) % MOD;
                v[i] = m["e"] % MOD;
            }
        }
        for (int i = 0; i < len; ++i) {
            if (s[i] == 'a') {
                m2["myhea"] = (m2["myhea"] + m2["myhe"]) % MOD;
                v[i] = (m2["myhe"] * v[i]) % MOD;
            }
            if (s[i] == 'm') {
                m2["m"] = (m2["m"] + 1) % MOD;
            }
            if (s[i] == 'y') {
                m2["my"] = (m2["my"] + m2["m"]) % MOD;
                v[i] = (m2["m"] * v[i]) % MOD;
                
            }
            if (s[i] == 'h') {
                m2["myh"] = (m2["myh"] + m2["my"]) % MOD;
                m2["myheartisth"] = (m2["myheartisth"] + m2["myheartist"]) % MOD;
                v[i] = ((v[i]* m2["my"]) + (v2[i] * m2["myheartist"])) % MOD;

            }
            if (s[i] == 'e') {
                m2["myhe"] = (m2["myhe"] + m2["myh"]) % MOD;
                m2["myheartisthine"] = (m2["myheartisthine"] + m2["myheartisthin"]) % MOD;
                v[i] = ((v[i] * m2["myh"]) + m2["myheartisthin"]) % MOD;
            }
            if (s[i] == 'r') {
                m2["myhear"] = (m2["myhear"] + m2["myhea"]) % MOD;
                v[i] = ((m2["myhea"] * v[i])) % MOD;
            }
            if (s[i] == 't') {
                m2["myheart"] = (m2["myheart"] + m2["myhear"]) % MOD;
                m2["myheartist"] = (m2["myheartist"]+m2["myheartis"]) % MOD;
                v[i] = ((v[i] * m2["myhear"]) + (v2[i] * m2["myheartis"])) % MOD;
            }
            if (s[i] == 'i') {
                m2["myhearti"] = (m2["myhearti"] + m2["myheart"]) % MOD;
                m2["myheartisthi"] = (m2["myheartisthi"] + m2["myheartisth"]) % MOD;
                v[i] = (v[i] * m2["myheart"] + v2[i] * m2["myheartisth"])% MOD;
            }
            if (s[i] == 's') {
                m2["myheartis"] = (m2["myheartis"] + m2["myhearti"]) % MOD;
                v[i] = (m2["myhearti"] * v[i]) % MOD;

            }
            if (s[i] == 'n') {
                m2["myheartisthin"] = (m2["myheartisthin"] + m2["myheartisthi"]) % MOD;
                v[i] = (m2["myheartisthi"] * v[i]) % MOD;
            }
        }
        for (int i = 0; i < len; ++i) {
            cout << v[i] % MOD << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}
