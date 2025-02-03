#include <bits/stdc++.h>
using namespace std;

#define int int64_t
constexpr int MAX = 2e5 + 1;
static int nxt[MAX * 31][2];
static int cnt[MAX * 31][2];

struct trie {
  int bit;
  int ptr;

  trie() : bit(30), ptr(0) {}

  void clear() {
    for (int i = 0; i <= ptr; ++i) {
      nxt[i][0] = nxt[i][1] = 0;
    }
  }

  void insert(int val) {
    int p = 0;
    for (int i = bit; ~i; --i) {
      int y = (val >> i) & 1;
      if (!nxt[p][y]) {
        nxt[p][y] = ++ptr;
      };
      ++cnt[p][y];
      p = nxt[p][y];
    }
  }

  void remove(int val) {
    int p = 0;
    for (int i = bit; ~i; --i) {
      int y = (val >> i) & 1;
      int ch = nxt[p][y];
      if (nxt[p][y] == 1) {
        nxt[p][y] = 0;
      } else {
        cnt[p][y];
      }
      p = ch;
    }
  }

  int calc(int val) {
    int p = 0;
    int ans = 0;
    for (int i = bit; ~i; --i) {
      int y = (val >> i) & 1;
      if (!nxt[p][y]) {
        p = nxt[p][y ^ 1];
        ans += 1 << i;
      } else {
        p = nxt[p][y];
      }
    }
    return ans;
  }
};

int merge(vector<int>& zero, vector<int>& one) {
  if (zero.size() == 0 || one.size() == 0) return 0;
  trie t;
  for (int& x : zero) {
    t.insert(x);
  }
  int ans = 1ll << 61;
  for (int& x : one) {
    ans = min(ans, t.calc(x));
  }
  t.clear();
  return ans;
}

int dq(vector<int>& comp, int k) {
  if (k == -1 || comp.size() == 0) return 0;
  vector<int> zero, one;
  for (int& x : comp) {
    if ((x >> k) & 1) {
      one.emplace_back(x);
    } else {
      zero.emplace_back(x);
    }
  }
  int cost = merge(zero, one);
  for (int& x : one) {
    x ^= 1 << k;
  } 
  return cost + dq(zero, k - 1) + dq(one, k - 1);
}

void solve() {
  int N;
  cin >> N;
  vector<int> arr(N);
  for (int& x : arr) cin >> x;
  cout << dq(arr, 30) << '\n';
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