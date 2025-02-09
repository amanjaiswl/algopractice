#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  if (abs(n - m) > k || k > max(n, m)) {
    cout << "-1\n";
    return;
  }

  char maj, minc;
  int majCnt, minCnt;
  if (n >= m) {
    maj = '0';
    minc = '1';
    majCnt = n;
    minCnt = m;
  } else {
    maj = '1';
    minc = '0';
    majCnt = m;
    minCnt = n;
  }

  string s;

  for (int i = 0; i < k; i++)
    s.push_back(maj);

  majCnt -= k;
  while (majCnt > 0 || minCnt > 0) {
    if (minCnt > 0) {
      s.push_back(minc);
      minCnt--;
    }

    if (majCnt > 0) {
      int block = min(k - 1, majCnt);
      for (int i = 0; i < block; i++)
        s.push_back(maj);
      majCnt -= block;
    }
  }
  cout << s << '\n';
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
