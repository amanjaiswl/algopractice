#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  if (n % 2 == 0) {
    cout << "-1\n";
    return;
  }

  for (int i = 1; i <= n; i++) {
    cout << ((2 * (i - 1)) % n) + 1 << " ";
  }

  cout << '\n';
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
