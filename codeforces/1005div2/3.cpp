#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<ll> lefty(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    lefty[i] = lefty[i - 1] + (a[i - 1] > 0 ? a[i - 1] : 0);
  }

  vector<ll> righty(n + 2, 0);
  for (int i = n; i >= 1; i--) {
    righty[i] = righty[i + 1] + (a[i - 1] < 0 ? abs(a[i - 1]) : 0);
  }

  ll ans = 0;
  for (int i = 0; i <= n; i++) {
    ans = max(ans, lefty[i] + righty[i + 1]);
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

/* dp solution gave memory exceeded
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp(int l, int r, vector<int> &a, vector<vector<ll>> &memo) {
  if (l > r)
    return 0;

  if (memo[l][r] != -1)
    return memo[l][r];

  ll ans = 0;

  for (int i = l; i <= r; i++) {

    if (a[i] > 0) {
      ll current = a[i] + dp(i + 1, r, a, memo);
      ans = max(ans, current);
    }

    else {
      ll current = -a[i] + dp(l, i - 1, a, memo);
      ans = max(ans, current);
    }
  }

  memo[l][r] = ans;
  return ans;
}

void solve() {
  int n;
  cin >> n;

  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<vector<ll>> memo(n + 2, vector<ll>(n + 2, -1));
  cout << dp(1, n, a, memo) << '\n';
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
*/
