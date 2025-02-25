#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {

  const ll MOD = 1000000007;
  ll n, k;
  cin >> n >> k;

  auto revNum = [&](ll n, ll p) -> ll {
    ll t = n, r = 0;
    while (t) {
      r = (r * p + t % p) % MOD;
      t /= p;
    }
    return r;
  };

  ll ans = 0;

  ll upto = min(k, n);

  for (ll p = 2; p <= upto; p++) {
    ans = (ans + revNum(n, p)) % MOD;
  }

  if (k > n)
    ans = (ans + ((k - n) % MOD) * (n % MOD)) % MOD;
  cout << ans % MOD << '\n';
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
