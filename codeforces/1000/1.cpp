#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int a, b;
  cin >> a >> b;

  if (a == 1 && b == 1)
    cout << 1 << '\n';
  else
    cout << abs(a - b) << '\n';
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
