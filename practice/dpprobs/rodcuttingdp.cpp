#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {

  int rod_len = 5;
  vector<pair<int, int>> len_profit = {{1, 2}, {2, 5}, {3, 7}, {4, 8}};
  vector<int> dp(rod_len + 1, 0);

  for (int i = 1; i <= rod_len; i++) {
    for (auto &[length, profit] : len_profit) {
      if (i >= length)
        dp[i] = max(dp[i], profit + dp[i - length]);
    }
  }

  cout << dp[rod_len] << '\n';
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
