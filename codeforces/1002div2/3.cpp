#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<vector<ll>> a(n, vector<ll>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }

  vector<int> k(n, 0);
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int j = n - 1; j >= 0; j--) {
      if (a[i][j] == 1)
        cnt++;
      else
        break;
    }

    k[i] = min(cnt, n - 1);
  }

  sort(k.begin(), k.end());

  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (k[i] >= ans)
      ans++;
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
