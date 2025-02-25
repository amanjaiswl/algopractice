#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> b(n - 2);
  for (int i = 0; i < n - 2; i++) {
    cin >> b[i];
  }

  for (int i = 1; i < n - 3; i++) {
    if (b[i - 1] == 1 && b[i] == 0 && b[i + 1] == 1) {
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
