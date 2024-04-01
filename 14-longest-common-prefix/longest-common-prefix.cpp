class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        string ans = strs[0];
        int c = ans.length();
        for (int i = 1; i < strs.size(); ++i) {
            int j = 0;
            if (!strs[i].size()) {
                c = 0;
                break;
            }
            while (strs[i][j] == ans[j]) {
                ++j;
                if (j == strs[i].size() || j == ans.size()) break;
            }
            c = min(c, j);
        }
        return ans.substr(0, c);
    }
};