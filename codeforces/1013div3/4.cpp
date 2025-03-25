#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {

  int n, m, k;
  cin >> n >> m >> k;

  auto maxrow = [&](ll L) -> ll {
    return (m / (L + 1)) * L + min(L, m % (L + 1));
  };

  int l = 1, h = m + 1;
  while (l < h) {
    int mid = l + (h - l) / 2;
    if (n * maxrow(mid) >= k)
      h = mid;
    else
      l = mid + 1;
  }
  cout << l << '\n';
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
