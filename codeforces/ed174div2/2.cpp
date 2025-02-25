#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> v(n, vector<int>(m));
  unordered_map<int, int> charge;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> v[i][j];
      if (charge.find(v[i][j]) == charge.end()) {
        charge[v[i][j]] = 1;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int c = v[i][j];
      if (j + 1 < m && v[i][j + 1] == c) {
        charge[c] = 2;
      }
      if (i + 1 < n && v[i + 1][j] == c) {
        charge[c] = 2;
      }
    }
  }

  ll total = 0;
  bool hasTwo = false;
  for (auto &p : charge) {
    total += p.second;
    if (p.second == 2)
      hasTwo = true;
  }

  cout << total - (hasTwo ? 2 : 1) << '\n';
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
