#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {

  int n, m;
  cin >> n >> m;

  cout << max(n, m) + 1 << '\n';
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
