#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  if (n == 1) {
    cout << "NO\n";
    return;
  }
  bool all = true;
  for (int i = 1; i < n; i++) {
    if (s[i] != s[0]) {
      all = false;
      break;
    }
  }
  if (all) {
    cout << "NO\n";
    return;
  }
  string r = s;
  reverse(r.begin(), r.end());
  if (s < r)
    cout << "YES\n";
  else if (k >= 1)
    cout << "YES\n";
  else
    cout << "NO\n";
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
