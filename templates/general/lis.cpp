int lis(vector<int>& v) {
  vector<int> lis;
  for (auto x : v) {
    auto it = lower_bound(lis.begin(), lis.end(), x);
    if (it == lis.end()) lis.push_back(x);
    else *it = x;
  }
  return lis.size();
}

int lnds(vector<int>& v) {
  vector<int> lnds;
  for (auto x : v) {
    auto it = upper_bound(lnds.begin(), lnds.end(), x);
    if (it == lnds.end()) lnds.push_back(x);
    else *it = x;
  }
  return lnds.size();
}