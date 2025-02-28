#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {

  int nodes, start, finish;
  cin >> nodes >> start >> finish;

  vector<vector<int>> graph(nodes + 1);
  for (int i = 1; i < nodes; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  vector<bool> seen(nodes + 1, false);
  vector<int> path;

  auto dfs = [&](auto &dfs, int cur, int target) -> bool {
    seen[cur] = true;
    path.push_back(cur);
    if (cur == target)
      return true;
    for (auto nxt : graph[cur])
      if (!seen[nxt] && dfs(dfs, nxt, target))
        return true;
    path.pop_back();
    return false;
  };

  dfs(dfs, start, finish);

  vector<bool> raasta(nodes + 1, false);
  for (auto v : path)
    raasta[v] = true;

  vector<int> dist(nodes + 1, INT_MAX);
  queue<int> q;
  for (auto v : path) {
    dist[v] = 0;
    q.push(v);
  }
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (auto nxt : graph[cur])
      if (dist[nxt] > dist[cur] + 1) {
        dist[nxt] = dist[cur] + 1;
        q.push(nxt);
      }
  }

  vector<int> permutation, others;
  for (int i = 1; i <= nodes; i++)
    if (!raasta[i])
      others.push_back(i);

  sort(others.begin(), others.end(),
       [&](int a, int b) { return greater<int>()(dist[a], dist[b]); });

  for (auto v : others)
    permutation.push_back(v);
  for (auto v : path)
    permutation.push_back(v);

  int permsize = permutation.size();
  for (int i = 0; i < permsize; i++)
    cout << permutation[i] << " ";

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
