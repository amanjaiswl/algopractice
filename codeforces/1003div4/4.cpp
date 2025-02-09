#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;

  vector<int> a(n), b(m);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int j = 0; j < m; j++) {
    cin >> b[j];
  }

  sort(b.begin(), b.end());

  int prev = -1e9;

  for (int i = 0; i < n; i++) {
    int opt1 = a[i];

    bool valid1 = (opt1 >= prev);

    int goal = prev + a[i];

    auto it = lower_bound(b.begin(), b.end(), goal);
    bool valid2 = false;
    int opt2 = 0;

    if (it != b.end()) {
      opt2 = (*it) - a[i];
      valid2 = (opt2 >= prev);
    }

    if (!valid1 && !valid2) {
      cout << "NO\n";
      return;
    }

    int chosen;
    if (valid1 && valid2)
      chosen = min(opt1, opt2);
    else if (valid1)
      chosen = opt1;
    else
      chosen = opt2;
    prev = chosen;
  }

  cout << "YES\n";
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
