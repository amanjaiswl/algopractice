#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  if (s.find('1') == string::npos) {
    cout << "0\n";
    return;
  }

  int idx = s.find('1');
  int ans = 0;

  for (int i = idx; i < n - 1; i++) {
    if (s[i] != s[i + 1])
      ans++;
  }
  cout << ans + 1 << '\n';
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
