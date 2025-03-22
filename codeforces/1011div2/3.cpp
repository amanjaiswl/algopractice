#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define MAX_LIMIT 1000000000000000000LL

void solve() {
  ll x, y;
  cin >> x >> y;
  if (x == y) {
    cout << "-1\n";
    return;
  }

  if ((x & y) == 0) {
    cout << "0\n";
    return;
  }

  ll maxi = max(x, y);
  ll L = 1;
  while (L <= maxi)
    L <<= 1;
  ll k = L - maxi;
  cout << k << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
