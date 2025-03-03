// https://codeforces.com/contest/2068/problem/A

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> facts;
  vector<vector<int>> pref(n, vector<int>(n, 0));
  vector<vector<int>> graph(n);
  vector<int> indeg(n, 0);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    facts.push_back({a, b});
    pref[a][b] = 1;
    graph[a].push_back(b);
    indeg[b]++;
  }
  vector<int> topo;
  queue<int> q;
  for (int i = 0; i < n; i++) {
    if (indeg[i] == 0)
      q.push(i);
  }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    topo.push_back(u);
    for (auto v : graph[u]) {
      indeg[v]--;
      if (indeg[v] == 0)
        q.push(v);
    }
  }
  if ((int)topo.size() == n) {
    cout << "YES" << '\n' << 1 << '\n';
    for (int i = 0; i < n; i++) {
      cout << topo[i] + 1 << (i == n - 1 ? '\n' : ' ');
    }
    return;
  }
  int k = 43;
  int T = k / 2 + 1;
  vector<vector<int>> ballots(k, vector<int>(n));
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n; j++) {
      ballots[i][j] = j;
    }
  }
  vector<vector<int>> factCount(n, vector<int>(n, 0));
  for (int r = 0; r < k; r++) {
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int a = ballots[r][i], b = ballots[r][j];
        if (pref[a][b])
          factCount[a][b]++;
      }
    }
  }
  auto totalScore = [&]() -> int {
    int score = 0;
    for (auto &f : facts) {
      int a = f.first, b = f.second;
      if (factCount[a][b] < T)
        score += (T - factCount[a][b]);
    }
    return score;
  };
  int score = totalScore();
  int iter = 0;
  const int ITER_LIMIT = 10000000;
  double temperature = 1000.0;
  double cooling = 0.99999;
  while (iter < ITER_LIMIT && score > 0) {
    iter++;
    int r = rand() % k;
    int i = rand() % (n - 1);
    int X = ballots[r][i], Y = ballots[r][i + 1];
    int delta = 0;
    if (pref[X][Y]) {
      int c = factCount[X][Y];
      if (c < T)
        delta += 1;
      else if (c == T)
        delta += 1;
    }
    if (pref[Y][X]) {
      int c = factCount[Y][X];
      if (c < T)
        delta -= 1;
    }
    if (delta <= 0 ||
        (exp(-delta / temperature) > ((double)rand() / RAND_MAX))) {
      swap(ballots[r][i], ballots[r][i + 1]);
      if (pref[X][Y])
        factCount[X][Y]--;
      if (pref[Y][X])
        factCount[Y][X]++;
      score += delta;
    }
    temperature *= cooling;
    if (iter % 1000000 == 0) {
      int r2 = rand() % k;
      for (int p = 0; p < n; p++) {
        for (int q = p + 1; q < n; q++) {
          int a = ballots[r2][p], b = ballots[r2][q];
          if (pref[a][b])
            factCount[a][b]--;
        }
      }
      random_shuffle(ballots[r2].begin(), ballots[r2].end());
      for (int p = 0; p < n; p++) {
        for (int q = p + 1; q < n; q++) {
          int a = ballots[r2][p], b = ballots[r2][q];
          if (pref[a][b])
            factCount[a][b]++;
        }
      }
      score = totalScore();
    }
  }
  if (score > 0) {
    cout << "NO" << '\n';
    return;
  }
  cout << "YES" << '\n' << k << '\n';
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n; j++) {
      cout << ballots[i][j] + 1 << (j == n - 1 ? '\n' : ' ');
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
