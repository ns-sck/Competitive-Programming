#include<bits/stdc++.h>
#define inf INT_MAX
#define ll long long
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define fri(b) freopen(b,"r",stdin)
#define fro(b) freopen(b,"w",stdout)
#define bassifir(a) __builtin_clz(a)
#define sonsifir(a) __builtin_ctz(a)
#define birsay(a) __builtin_popcount(a)
#define UPP 100013ll
#define MOD (ll)1e9+7ll 



using namespace std;

int dp[3013][3013];
string s1,s2;

void fillLCS () {
	for(int i = 0; i <= s1.length(); i++) {
		for(int j = 0; j <= s2.length(); j++) {
			if(i == 0 || j == 0) {
				dp[i][j] = 0;
			}
			else if (s1[i-1] == s2[j-1]) {
				dp[i][j] = dp[i -1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
}

string findLCS () {
	string ans = "";
	stack <char> st;
	int i = s1.length();
	int j = s2.length();
	while(i > 0 && j > 0) {
		if(dp[i-1][j] == dp[i][j]) {
			i--;
		}
		else if(dp[i][j-1] == dp[i][j]) {
			j--;
		}
		else {
			i--;
			j--;
			st.push(s1[i]);
		}
	}
	while(!st.empty()) {
		ans.push_back(st.top());
		st.pop();
	}
	return ans;

}




int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);
	cout.tie(0);
	// fri("contestgir.txt");
	// fro("contestcik.txt");
	int n;
	cin>>n;
	cin>>s1;
	s2 = "";
	int maxi = 0;
	for(int i = 0; i < n; i++) {
		s2.push_back(s1[0]);
		s1.erase(s1.begin());
		fillLCS();
		string ans = findLCS();
		maxi = max(maxi, (int)ans.length());
	}
	cout << 2*maxi << "\n";
	return 0;
}

