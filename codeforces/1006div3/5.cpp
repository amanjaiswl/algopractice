#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  ll k;
  cin >> k;
  if (k == 0) {
    cout << "1\n"
         << "0 0" << '\n';
    return;
  }
  vector<int> cols;
  while (k > 0) {
    int h = 2;
    while ((ll)h * (h - 1) / 2 <= k)
      h++;
    h--;
    cols.push_back(h);
    k -= (ll)h * (h - 1) / 2;
  }

  int tot = 0;
  for (auto c : cols)
    tot += c;
  cout << tot << '\n';
  for (int i = 0; i < (int)cols.size(); i++) {
    for (int j = 0; j < cols[i]; j++) {
      cout << i << " " << i * 10000 + j << '\n';
    }
  }
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
