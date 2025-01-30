#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int rod_cut(int rod_len, vector<pair<int, int>> &len_profit) {
  if (rod_len == 0)
    return 0;

  int profit = 0;

  for (auto &[len, prof] : len_profit) {
    if (rod_len >= len) {
      int curr_prof = prof + rod_cut(rod_len - len, len_profit);
      profit = max(curr_prof, profit);
    }
  }
  return profit;
}

void solve() {
  int rod_len = 5;
  vector<pair<int, int>> len_profit = {{1, 2}, {2, 5}, {3, 7}, {4, 8}};
  int ans = rod_cut(rod_len, len_profit);

  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;

  while (t--) {
    solve();
  }
  return 0;
}
