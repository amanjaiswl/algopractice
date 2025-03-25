#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;

  priority_queue<int> Q;

  ll ans = 0;

  for (int i = 0; i < n; i++) {
    int d;
    cin >> d;
    Q.push(d);
    if ((n - i) % (k + 1) == 0) {
      ans += Q.top();
      Q.pop();
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
