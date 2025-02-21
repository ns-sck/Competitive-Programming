#include <bits/stdc++.h>
using namespace std;

#define int int64_t

struct line {
	int m, c;
	line(int m_, int c_) : m(m_), c(c_) {}
};

struct CHT {
	vector<line> lines;
	bool bad(line l1, line l2, line l3) {
		// m1x + c1, m2x + c2, m3x + c3;
		// m1x + c1 = m2x + c2
		// x1 = c2 - c1 / m1 - m2
		// m2x + c2 = m3x + c3
		// x2 = c3 - c2 / m2x - m3x
		// bad == x1 >= x2
		__int128 a = (__int128) (l2.c - l1.c) * (l2.m - l3.m);
		__int128 b = (__int128) (l3.c - l2.c) * (l1.m - l2.m);
		return a >= b;
	}

	void add(line a) {
		lines.emplace_back(a);
		int sz = lines.size();
		while (sz >= 3 && bad(lines[sz - 3], lines[sz - 2], lines[sz - 1])) {
			lines.erase(lines.end() - 2);
			--sz;
		}
	}

	inline int get(int idx, int x) {
		return lines[idx].m * x + lines[idx].c;
	}

	int query(int x) {
		int lo = 0, hi = lines.size() - 1;
		int ans = 0;
		while (lo <= hi) {
			int mi1 = lo + (hi - lo) / 3;
			int mi2 = hi - (hi - lo) / 3;
			if (get(mi1, x) <= get(mi2, x)) {
				hi = mi2 - 1;
				ans = get(mi1, x);
			} else {
				lo = mi1 + 1;
				ans = get(mi2, x);
			}
		}
		return ans;
	}

};

void solve() {
  // jump j to i with cost (arr[i] - arr[j])^2 + C
  int N, C;
  cin >> N >> C;
  vector<int> arr(N);
  vector<int> dp(N);
  for (int& x : arr) cin >> x;
  CHT cht;
  dp[0] = 0;
  cht.add({-2 * arr[0], arr[0] * arr[0] + dp[0]});
  for (int i = 1; i < N; ++i) {
    dp[i] = C + arr[i] * arr[i] + cht.query(arr[i]);
    cht.add({-2 * arr[i], arr[i] * arr[i] + dp[i]});
  }
  cout << dp[N - 1] << '\n';
}

signed main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}