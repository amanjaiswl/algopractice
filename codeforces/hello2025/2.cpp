#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  vector<int> freq;
  freq.reserve(n);

  int currCount = 1;
  for (int i = 1; i < n; i++) {
    if (v[i] == v[i - 1]) {
      currCount++;
    } else {
      freq.push_back(currCount);
      currCount = 1;
    }
  }
  freq.push_back(currCount);

  int len = freq.size();

  sort(freq.begin(), freq.end());

  int remove = 0;
  for (auto c : freq) {
    if (k >= c) {
      k -= c;
      remove++;
    } else {
      cout << (len - remove) << "\n";
      return;
    }
  }

  cout << "1\n";
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
