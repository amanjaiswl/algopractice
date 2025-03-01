#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using int128 = __int128;

void solve() {
  int r, c;
  cin >> r >> c;
  vector<string> grid(r);
  for (int i = 0; i < r; i++) {
    cin >> grid[i];
  }

  vector<int> row_count(r, 0), col_count(c, 0);
  vector<vector<int>> row_empty(r), col_empty(c);
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (grid[i][j] == '.') {
        row_count[i]++;
        col_count[j]++;
        row_empty[i].push_back(j);
        col_empty[j].push_back(i);
      }
    }
  }

  ll ans = 0;
  for (int i = 0; i < r; i++) {
    int n = row_empty[i].size();
    if (n < 2)
      continue;
    ll s = 0, q = 0;
    for (int j : row_empty[i]) {
      ll val = row_count[i] + col_count[j] - 3;
      s += val;
      q += val * val;
    }
    ll contrib =
        (ll)(((int128)s * s) - q - (int128)(row_count[i] - 2) * n * (n - 1));
    ans += contrib;
  }

  for (int j = 0; j < c; j++) {
    int m = col_empty[j].size();
    if (m < 2)
      continue;
    ll s = 0, q = 0;
    for (int i : col_empty[j]) {
      ll val = col_count[j] + row_count[i] - 3;
      s += val;
      q += val * val;
    }
    ll contrib =
        (ll)(((int128)s * s) - q - (int128)(col_count[j] - 2) * m * (m - 1));
    ans += contrib;
  }

  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
