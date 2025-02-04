#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, s1, s2;
  cin >> n >> s1 >> s2;

  vector<vector<int>> g1(n + 1), g2(n + 1);
  int m1;
  cin >> m1;
  for (int i = 0; i < m1; i++) {
    int a, b;
    cin >> a >> b;
    g1[a].push_back(b);
    g1[b].push_back(a);
  }

  int m2;
  cin >> m2;
  for (int i = 0; i < m2; i++) {
    int c, d;
    cin >> c >> d;
    g2[c].push_back(d);
    g2[d].push_back(c);
  }

  vector<bool> good(n + 1, false);
  for (int v = 1; v <= n; v++) {
    sort(g2[v].begin(), g2[v].end());
  }

  for (int v = 1; v <= n; v++) {
    for (int u : g1[v]) {
      if (binary_search(g2[v].begin(), g2[v].end(), u)) {
        good[v] = true;
        break;
      }
    }
  }

  bool anyGood = false;
  for (int v = 1; v <= n; v++) {
    if (good[v]) {
      anyGood = true;
      break;
    }
  }

  if (!anyGood) {
    cout << -1 << '\n';
    return;
  }

  auto encode = [&](int a, int b) -> int { return (a - 1) * n + (b - 1); };

  int total = n * n;
  const ll INF = 1e18;
  vector<ll> dist(total, INF);

  int start = encode(s1, s2);
  dist[start] = 0;
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
      pq;
  pq.push({0, start});

  while (!pq.empty()) {
    auto [d, idx] = pq.top();
    pq.pop();
    if (d != dist[idx])
      continue;

    int v1 = idx / n + 1;
    int v2 = idx % n + 1;

    for (int u1 : g1[v1]) {
      for (int u2 : g2[v2]) {
        int nxt = encode(u1, u2);
        ll nd = d + llabs(u1 - u2);
        if (nd < dist[nxt]) {
          dist[nxt] = nd;
          pq.push({nd, nxt});
        }
      }
    }
  }

  ll ans = INF;
  for (int v = 1; v <= n; v++) {
    if (!good[v])
      continue;
    int state = encode(v, v);
    ans = min(ans, dist[state]);
  }

  cout << (ans == INF ? -1 : ans) << '\n';
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
