#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(),(x).end()
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	while (T--)
	{
		int n, i;
		cin >> n;
		vector<int> l(n), r(n), a(n);
		for (i = 0; i < n; i++) cin >> l[i] >> r[i];
		vector<vector<int>> e(n, vector<int>(0));
		for (i = 1; i < n; i++)
		{
			int u, v;
			cin >> u >> v;
			--u, --v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		long long ans = 0;
		function<void(int, int)> dfs = [&](int u, int p) {
			int mx = l[u];
			for (int v : e[u])
			{
				if (v == p) continue;
				dfs(v, u);
				mx = max(mx, a[v]);
			}
			a[u] = min(mx, r[u]);
			for (int v : e[u]) ans += max(0, a[v] - a[u]);
		};
		dfs(0, -1);
		cout << ans + a[0] << "\n";
	}
}