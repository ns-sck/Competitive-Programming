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