#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// two boxes are given. use any number of them to make maximum height.

vector<vector<int>> orientations(vector<int> &box) {
  vector<vector<int>> orient;
  orient.push_back({max(box[0], box[1]), min(box[0], box[1]), box[2]});
  orient.push_back({max(box[1], box[2]), min(box[1], box[2]), box[0]});
  orient.push_back({max(box[2], box[0]), min(box[2], box[0]), box[1]});

  return orient;
}

void solve() {
  vector<vector<int>> boxes = {
      {2, 1, 4},
      {3, 2, 5},
  };

  vector<vector<int>> orientedboxes;

  for (auto box : boxes) {
    vector<vector<int>> perms = orientations(box);
    orientedboxes.insert(orientedboxes.end(), perms.begin(), perms.end());
  }

  sort(orientedboxes.begin(), orientedboxes.end(),
       [](vector<int> &a, vector<int> &b) {
         return (a[0] * a[1]) > (b[0] * b[1]);
       });

  int n = orientedboxes.size();

  vector<int> dp(n, 0), result(n, -1);

  for (int i = 0; i < n; i++) {
    dp[i] = orientedboxes[i][2];
  }

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (orientedboxes[i][0] < orientedboxes[j][0] &&
          orientedboxes[i][1] < orientedboxes[j][1]) {
        if (dp[i] < dp[j] + orientedboxes[i][2]) {
          dp[i] = dp[j] + orientedboxes[i][2];
          result[i] = j;
        }
      }
    }
  }

  auto it = max_element(dp.begin(), dp.end());
  int maxh = *it;

  cout << "max height: " << maxh << '\n';
  cout << "the boxes will be top to bottom : ";

  int idx = distance(dp.begin(), it);

  while (idx != -1) {
    cout << "(" << orientedboxes[idx][0] << ", " << orientedboxes[idx][1]
         << ", " << orientedboxes[idx][2] << ") -> ";

    idx = result[idx];
  }

  cout << "END\n";
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
