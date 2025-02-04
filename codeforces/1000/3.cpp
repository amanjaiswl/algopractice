#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> graph(n + 1);
  vector<int> degree(n + 1, 0);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
    degree[u]++;
    degree[v]++;
  }

  for (int u = 1; u <= n; u++)
    sort(graph[u].begin(), graph[u].end());
  vector<pair<int, int>> L;
  L.reserve(n);

  for (int u = 1; u <= n; u++)
    L.push_back({degree[u], u});

  sort(L.rbegin(), L.rend());

  ll best_nonadj = -1;
  for (int u = 1; u <= n; u++) {
    ll candidate = -1;
    for (auto &p : L) {
      int v = p.second;
      if (v == u)
        continue;
      if (binary_search(graph[u].begin(), graph[u].end(), v))
        continue;
      candidate = (ll)degree[u] + degree[v] - 1;
      break;
    }
    best_nonadj = max(best_nonadj, candidate);
  }

  ll best_adj = -1;
  for (int u = 1; u <= n; u++) {
    for (int v : graph[u])
      if (v > u)
        best_adj = max(best_adj, (ll)degree[u] + degree[v] - 2);
  }

  ll ans = max(best_nonadj, best_adj);
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
