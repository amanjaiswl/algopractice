#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  vector<vector<int>> adj(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<char> ans(n + 1, '0');

  for (int u = 1; u <= n; u++) {
    for (int x : adj[u]) {

      if (u < x) {
        if (a[u] == a[x])
          ans[a[u]] = '1';
      }
    }
  }

  for (int i = 1; i <= n; i++) {

    if (adj[i].size() < 2)
      continue;
    unordered_map<int, int> freq;
    for (int neighbor : adj[i]) {
      freq[a[neighbor]]++;
    }
    for (auto p : freq) {
      if (p.second >= 2)
        ans[p.first] = '1';
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i];
  }
  cout << '\n';
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
