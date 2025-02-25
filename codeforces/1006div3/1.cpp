#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, k, p;
  cin >> n >> k >> p;

  if (k == 0) {
    cout << "0\n";
    return;
  }

  int cnt = abs(k) / p;
  if (abs(k) % p)
    cnt++;

  if (cnt > n)
    cout << "-1\n";

  else
    cout << cnt << '\n';
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
