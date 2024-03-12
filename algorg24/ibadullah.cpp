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

int lis(vector<int>& nums)
{
    int n = nums.size();
    vector<int> ans;
    int j = 0;
    for (j = 0; j < n; ++j) {
        if (nums[j] > 0) {
            ans.push_back(nums[j]);
            ++j;
            break;
        }
    }
    for (int i = j; i < n; ++i) {
        if (nums[i] <= 0)
            continue;
        if (nums[i] >= ans.back()) {
            ans.push_back(nums[i]);
        }
        else {
            int low = upper_bound(ans.begin(), ans.end(),nums[i]) - ans.begin();
            ans[low] = nums[i];
        }
    }
    return ans.size();
}

int32_t main() {
	
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            v[i] -= i;
        }

        cout << n - lis(v) << '\n';
    }
    return 0;
}
