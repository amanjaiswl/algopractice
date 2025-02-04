#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<ll> v(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
  }

  if (k == n) {
    int m = k / 2;
    int cost = m + 1;
    for (int i = 1; i <= m; i++) {
      if (v[2 * i] != i) {
        cost = i;
        break;
      }
    }
    cout << cost << '\n';
    return;
  }

  int Lmax = n - k + 1;
  int extra = n - k;
  int best = INT_MAX;
  int maxS2 = n - k + 1;

  for (int L = 1; L <= Lmax; L++) {
    int candidate = -1;
    int rLimit = maxS2;
    bool found = false;
    for (int r = 1; r <= rLimit; r++) {
      int pos = L + r;
      if (v[pos] != r) {
        candidate = r;
        found = true;
        break;
      }
    }
    if (!found) {
      candidate = rLimit + 1;
    }
    best = min(best, candidate);
    if (best == 1)
      break;
  }
  cout << best << '\n';
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
