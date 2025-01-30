#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> dp(n, vector<int>(m, 0));

  dp[0][0] = 1;

  for (int j = 1; j < m; j++) {
    dp[0][j] = 1;
  }

  for (int i = 1; i < n; i++) {
    dp[i][0] = 1;
  }

  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }
  }

  cout << dp[n - 1][m - 1] << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
