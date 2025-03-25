#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int NMAX = 10000000;
vector<bool> isprime(NMAX + 1, true);
vector<int> prime;

void pre() {
  isprime[0] = isprime[1] = false;
  for (int i = 2; i * i <= NMAX; i++) {
    if (isprime[i])
      for (int j = i * i; j <= NMAX; j += i)
        isprime[j] = false;
  }
  for (int i = 2; i <= NMAX; i++)
    if (isprime[i])
      prime.push_back(i);
}

void solve() {
  int n;
  cin >> n;
  ll ans = 0;
  for (int p : prime) {
    if (p > n)
      break;
    ans += n / p;
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  pre();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
