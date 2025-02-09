#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {

  string s;
  cin >> s;

  int n = s.size();

  for (int i = 0; i < n - 1; i++) {
    if (s[i] == s[i + 1]) {
      cout << "1\n";
      return;
    }
  }

  cout << n << '\n';
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
