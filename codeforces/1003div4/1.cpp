#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  string s;
  cin >> s;

  int len = s.size();

  string news = "";
  for (int i = 0; i < len - 2; i++)
    news += s[i];

  cout << news + 'i' << '\n';
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
