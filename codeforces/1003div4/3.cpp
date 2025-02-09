#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int b1;
  cin >> b1;

  int prev = -1e9;

  for (int i = 0; i < n; i++) {

    int opt1 = a[i];
    int opt2 = b1 - a[i];

    int low = min(opt1, opt2);
    int high = max(opt1, opt2);

    if (low >= prev)
      prev = low;
    else if (high >= prev)
      prev = high;
    else {
      cout << "NO\n";
      return;
    }
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
