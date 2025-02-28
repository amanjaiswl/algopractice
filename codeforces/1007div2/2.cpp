#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  ll n;
  cin >> n;
  ll total = n * (n + 1) / 2;

  auto perfsq = [](ll x) -> bool {
    ll r = floor(sqrt((long double)x));
    return r * r == x;
  };

  if (perfsq(total)) {
    cout << "-1\n";
    return;
  }

  vector<ll> perm;

  ll prefix = 0;
  ll i = 1;

  while (i <= n) {
    if (i < n && perfsq(prefix + i)) {
      perm.push_back(i + 1);
      prefix += i + 1;
      perm.push_back(i);
      prefix += i;
      i += 2;
    } else {
      perm.push_back(i);
      prefix += i;
      i++;
    }
  }

  for (ll x : perm)
    cout << x << " ";

  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
