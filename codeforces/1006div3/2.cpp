#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  ll d = 0, u = 0;
  for (auto c : s) {
    if (c == '-')
      d++;
    else
      u++;
  }

  if (d < 2 || u == 0) {
    cout << "0\n";
    return;
  }

  ll x = d / 2;
  ll y = d - x;

  cout << u * x * y << '\n';
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
