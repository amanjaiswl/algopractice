#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  int req[10] = {0};
  req[0] = 3;
  req[1] = 1;
  req[2] = 2;
  req[3] = 1;
  req[5] = 1;

  int count[10] = {0};
  int ans = 0;

  for (int i = 0; i < n; i++) {
    count[v[i]]++;

    bool possible =
        (count[0] >= req[0] && count[1] >= req[1] && count[2] >= req[2] &&
         count[3] >= req[3] && count[5] >= req[5]);

    if (possible) {
      ans = i + 1;
      break;
    }
  }

  cout << ans << '\n';
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
