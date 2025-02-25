#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int &i : a)
    cin >> i;

  const ll MOD = 998244353;

  ll dp1 = 0, dp2 = 0, dp3 = 0;

  for (auto x : a) {
    if (x == 1)
      dp1 = (dp1 + 1) % MOD;

    if (x == 2)
      dp2 = (dp1 + 2 * dp2) % MOD;

    if (x == 3)
      dp3 = (dp3 + dp2) % MOD;
  }

  cout << dp3 % MOD << '\n';
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
