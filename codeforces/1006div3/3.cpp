#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, x;
  cin >> n >> x;

  if (n == 1) {
    cout << x << '\n';
    return;
  }

  int m = 0;
  for (int i = 0; i < 31; i++) {
    if (!(x & (1 << i))) {
      m = 1 << i;
      break;
    }
  }

  vector<int> ans;
  int cnt = min(n, m), orv = 0;
  for (int i = 0; i < cnt; i++) {
    ans.push_back(i);
    orv |= i;
  }

  if (orv != x) {
    if (ans.size() < n)
      ans.push_back(x);
    else
      ans.back() = x;
  }

  while (ans.size() < n)
    ans.push_back(0);

  for (auto a : ans)
    cout << a << " ";

  cout << '\n';
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
