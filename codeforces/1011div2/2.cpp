#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a)
    cin >> x;

  vector<pair<int, int>> ops;
  while (a.size() > 1) {
    bool z = false;
    for (auto x : a) {
      if (x == 0) {
        z = true;
        break;
      }
    }

    if (!z) {
      ops.push_back({1, a.size()});
      a = {0};
    }

    else {
      int p = 0;
      while (a[p] != 0)
        p++;
      int l, r;
      if (p < a.size() - 1) {
        l = p + 1;
        r = p + 2;
      } else {
        l = p;
        r = p + 1;
      }
      int x = a[l - 1], y = a[r - 1], m;
      if (x && y)
        m = 0;
      else if ((x == 0 && y != 1) || (y == 0 && x != 1))
        m = 1;
      else
        m = 2;

      ops.push_back({l, r});
      vector<int> b;
      for (int i = 0; i < l - 1; i++)
        b.push_back(a[i]);

      b.push_back(m);
      for (int i = r; i < a.size(); i++)
        b.push_back(a[i]);

      a = b;
    }
  }
  cout << ops.size() << '\n';
  for (auto &p : ops)
    cout << p.first << " " << p.second << '\n';
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
