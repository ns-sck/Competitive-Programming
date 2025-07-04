#include <bits/stdc++.h>
using namespace std;

#define int int64_t

constexpr int MAX = 1e6 + 1;

void solve() {
  int tc = 1;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int mn = 1;
  int mx = 5e6 + 1;
  int tt[30] = {0,  2,  2,    3,   11,   7,   21,  41, 40, 71,
                10, 7,  444,  410, 62,   424, 777, 12, 4,  3,
                7,  14, 5111, 156, 7500, 1,   2,   5,  4,  1000};
  int mxN[30] = {0,      26,      30,      40,      100,     145,
                 500,    768,     1600,    2600,    4900,    7400,
                 11000,  16000,   27000,   41000,   70000,   130000,
                 200000, 280000,  307000,  410000,  501000,  702020,
                 901001, 1000000, 1000000, 1000000, 1000000, 1000000};
  // while (tc < 30) {
  //   string str = "input";
  //   if (tc < 10) str += '0';
  //   str += to_string(tc);
  //   str += ".txt";
  //   ofstream out(str);
  //   int t = tt[tc];
  //   int tot = mxN[tc];
  //   int xxx = 0;
  //   out << t << '\n';
  //   while (t--) {
  //     int avg = tot / (t + 1) * 2;
  //     int N = min(tot - 2 * t, 2 + rng() % avg);
  //     if (t == 0) N = tot;
  //     xxx += N;
  //     assert(N >= 2);
  //     tot -= N;
  //     int K = max(3ll, 1 + rng() % N);
  //     K &= ~1;
  //     unordered_set<int> s;
  //     while (s.size() < K) {
  //       int x = 1 + (rng() % N);
  //       s.insert(x);
  //     }
  //     out << N << ' ' << K << '\n';
  //     for (int x : s) {
  //       out << x << ' ';
  //     }
  //     out << '\n';
  //     vector<int> nodes(N - 1);
  //     vector<int> parents(N);
  //     iota(nodes.begin(), nodes.end(), 1);
  //     shuffle(nodes.begin(), nodes.end(), rng);
  //     vector<int> component = {1};
  //     for (int i = 0; i < N - 1; ++i) {
  //       int idx = nodes[i];
  //       int sz = component.size();
  //       int p = rng() % sz;
  //       parents[idx] = component[p];
  //       component.push_back(idx + 1);
  //     }
  //     for (int i = 1; i < N; ++i) {
  //       out << parents[i] << " \n"[i == N - 1];
  //     }
  //   }
  //   assert(xxx == mxN[tc]);
  //   tc++;
  // }
  // while (tc < 35) {
  //   string str = "input";
  //   if (tc < 10) str += '0';
  //   str += to_string(tc);
  //   str += ".txt";
  //   ofstream out(str);
  //   int t = 2 + (rng() % 4);
  //   out << t << '\n';
  //   int tot = 1e6;
  //   while (t--) {
  //     int avg = tot / (t + 1) * 2;
  //     int N = min(tot - 2 * t, 2 + rng() % avg);
  //     if (t == 0) N = tot;
  //     assert(N >= 2);
  //     tot -= N;
  //     int K = max(3ll, 1 + rng() % N);
  //     if (K > N / 4) K = N / 4;
  //     K &= ~1;
  //     out << N << ' ' << K << '\n';
  //     bool ok = rng() % 2;
  //     for (int i = 2; i <= N && K; ++i) {
  //       if (__lg(i) & 1 && ok) continue;
  //       K--;
  //       out << i << ' ';
  //     }
  //     out << '\n';
  //     for (int i = 2; i <= N; ++i) {
  //       out << i / 2 << ' ';
  //     }
  //     out << '\n';
  //   }
  //   tc++;
  // }
  ofstream out("input35.txt");
  int t = 5;
  out << t << '\n';
  while (t--) {
    int N = 200000;
    int K = 190000 + rng() % 10000;
    K &= ~1;
    out << N << ' ' << K << '\n';
    vector<int> arr(200001);
    iota(arr.begin(), arr.end(), 1);
    shuffle(arr.begin() + 1, arr.end(), rng);
    for (int i = 1; i <= K; ++i) {
      out << arr[i] << ' ';
    }
    out << '\n';
    for (int i = 1; i < 200000; ++i) {
      out << arr[i - 1] << ' ';
    }
    out << '\n';
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}