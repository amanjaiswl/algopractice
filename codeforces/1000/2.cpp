#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, l, r;
  cin >> n >> l >> r;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  vector<int> seg, before, after;
  for (int i = 0; i < n; i++) {
    if (i >= l - 1 && i < r)
      seg.push_back(v[i]);
    else if (i < l - 1)
      before.push_back(v[i]);
    else
      after.push_back(v[i]);
  }

  ll S = accumulate(seg.begin(), seg.end(), 0LL);

  sort(seg.begin(), seg.end(), greater<int>());
  sort(before.begin(), before.end());
  sort(after.begin(), after.end());

  int szSeg = seg.size(), szBefore = before.size(), szAfter = after.size();
  vector<ll> prefSeg(szSeg + 1, 0), prefBefore(szBefore + 1, 0),
      prefAfter(szAfter + 1, 0);

  for (int i = 0; i < szSeg; i++)
    prefSeg[i + 1] = prefSeg[i] + seg[i];
  for (int i = 0; i < szBefore; i++)
    prefBefore[i + 1] = prefBefore[i] + before[i];
  for (int i = 0; i < szAfter; i++)
    prefAfter[i + 1] = prefAfter[i] + after[i];

  ll bestBefore = 0, bestAfter = 0;
  int pmax = min(szSeg, szBefore);
  for (int p = 1; p <= pmax; p++)
    bestBefore = max(bestBefore, prefSeg[p] - prefBefore[p]);

  pmax = min(szSeg, szAfter);
  for (int p = 1; p <= pmax; p++)
    bestAfter = max(bestAfter, prefSeg[p] - prefAfter[p]);

  ll ans = S - max(bestBefore, bestAfter);
  cout << ans << "\n";
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
