#define ll long long
class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        s = s.substr(s[0] == '-', s.size() - (s[0] == '-'));
        int sz = s.size();
        int j = 1 - (sz % 2);
        for (int i = sz/2 - 1 + (sz % 2); ~i; --i) {
            swap(s[i], s[i+j]);
            j += 2;
        }
        ll ans = stoll(s);
        if (ans >= INT_MAX || ans <= INT_MIN) return 0;
        if (x < 0) return -ans;
        return ans;
    }
};