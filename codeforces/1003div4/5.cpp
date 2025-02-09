#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> v(n, vector<int>(m));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> v[i][j];
    }
  }

  vector<pair<ll, ll>> arr(n);

  for (int i = 0; i < n; i++) {
    ll total = 0, prefixsum = 0, score = 0;
    for (int j = 0; j < m; j++) {
      total += v[i][j];
      prefixsum += v[i][j];
      score += prefixsum;
    }
    arr[i] = {total, score};
  }

  sort(arr.begin(), arr.end(), greater<pair<ll, ll>>());

  ll ans = 0, gtotal = 0;
  for (int i = 0; i < n; i++) {
    ans += arr[i].second + gtotal * m;
    gtotal += arr[i].first;
  }

  cout << ans << '\n';
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
