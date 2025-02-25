#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int lefty = 0, righty = 0;
  int best = 0;

  for (int l = 0; l < n; l++) {
    int cntless = 0, cntgreat = 0;
    for (int r = l + 1; r < n; r++) {
      if (a[r] > a[l])
        cntgreat++;
      else if (a[r] < a[l])
        cntless++;

      int net = cntgreat - cntless;
      if (net < best) {
        best = net;
        lefty = l;
        righty = r;
      }
    }
  }

  cout << lefty + 1 << " " << righty + 1 << '\n';
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
