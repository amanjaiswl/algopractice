#include <bits/stdc++.h>
// can the target be achieved from the set of coins. output yes or no
using namespace std;

using ll = long long;

void solve() {
  vector<int> v = {1, 2, 3, 4, 5, 10, 20, 100};
  const int target = 35;

  bitset<target + 1> possible;
  possible.set(0);

  for (auto c : v)
    possible |= (possible << c);

  cout << (possible[target] ? "yes\n" : "no\n");
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
