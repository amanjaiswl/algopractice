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

  vector<int> freq(n + 1, 0);
  for (int i = 0; i < n; i++)
    freq[v[i]]++;

  int maxlen = 0, lefty = -1, righty = -1;
  int start = 0;

  while (start < n) {
    if (freq[v[start]] != 1) {
      start++;
      continue;
    }

    int end = start;
    while (end < n && freq[v[end]] == 1)
      end++;

    int curlen = end - start;
    if (curlen > maxlen) {
      maxlen = curlen;
      lefty = start;
      righty = end - 1;
    }
    start = end;
  }

  if (maxlen == 0)
    cout << "0\n";
  else
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
