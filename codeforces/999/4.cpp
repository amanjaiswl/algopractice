#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (auto &x : a)
    cin >> x;
  vector<int> b(m);
  for (auto &x : b)
    cin >> x;

  ll sum_a = 0, sum_b = 0;
  for (auto x : a)
    sum_a += x;
  for (auto x : b)
    sum_b += x;

  if (sum_a != sum_b) {
    cout << "NO\n";
    return;
  }

  sort(a.begin(), a.end(), greater<int>());

  priority_queue<int> pq;
  for (auto x : b)
    pq.push(x);

  int i = 0;
  bool possible = true;

  while (!pq.empty() && i < n && possible) {
    int z = pq.top();
    pq.pop();

    if (z == a[i]) {
      i++;
      continue;
    }

    if (z < a[i]) {
      possible = false;
      break;
    }

    if (z == 1) {
      possible = false;
      break;
    }

    int x = z / 2;
    int y = z - x;

    if (abs(x - y) > 1) {
      possible = false;
      break;
    }

    pq.push(x);
    pq.push(y);
  }

  if (i == n && pq.empty()) {
    cout << "YES\n";
  } else {

    while (i < n && !pq.empty()) {
      int z = pq.top();
      pq.pop();
      if (z == a[i]) {
        i++;
        continue;
      }
      if (z < a[i]) {
        possible = false;
        break;
      }
      if (z == 1) {
        possible = false;
        break;
      }
      int x = z / 2;
      int y = z - x;
      if (abs(x - y) > 1) {
        possible = false;
        break;
      }
      pq.push(x);
      pq.push(y);
    }

    if (i == n && pq.empty() && possible) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
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
