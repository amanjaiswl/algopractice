#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  vector<int> b(m);
  for (int j = 0; j < m; j++)
    cin >> b[j];

  int size = 1 << m;
  vector<int> comb_magic(size);
  vector<int> op_cnt(size);

  for (int t = 0; t < size; t++) {
    int x = (1 << 30) - 1;
    for (int i = 0; i < m; i++) {
      if (t & (1 << i))
        x &= b[i];
    }
    comb_magic[t] = x;
    op_cnt[t] = __builtin_popcount(t);
  }

  vector<int> reduction(n * m);
  vector<int> minval_opcnt(m + 1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= m; j++)
      minval_opcnt[j] = (1 << 30) - 1;
    for (int t = 0; t < size; t++) {
      minval_opcnt[op_cnt[t]] =
          min(minval_opcnt[op_cnt[t]], a[i] & comb_magic[t]);
    }
    for (int j = 1; j <= m; j++) {
      reduction[i * m + j - 1] = minval_opcnt[j - 1] - minval_opcnt[j];
    }
  }

  ll ans = 0;
  for (int i = 0; i < n; i++)
    ans += a[i];
  sort(reduction.begin(), reduction.end(), greater<int>());
  for (int i = 0; i < k && i < reduction.size(); i++) {
    ans -= reduction[i];
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
