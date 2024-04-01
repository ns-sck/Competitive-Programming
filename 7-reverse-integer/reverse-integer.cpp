#define ll long long
class Solution {
public:
    int reverse(int x) {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        ll num = x;
        ll dig = 0;
        ll rev = 0;

        while (num != 0) {
            dig = num % 10;
            num = num / 10;
            rev = rev * 10 + dig;
        }
        
        if (rev > INT_MAX || rev < INT_MIN) return 0;
        return rev;
    }
};