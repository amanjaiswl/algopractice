/* this is naive approach

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> buildSP(const vector<ll> &vals) {
  int n = vals.size();
  int xMax = n / 2;

  vector<ll> sp(xMax + 1, 0LL);
  for (int i = 1; i <= xMax; i++) {
    ll gap = vals[n - i] - vals[i - 1];
    sp[i] = sp[i - 1] + gap;
  }

  return sp;
}

void solve() {
  int n, m;
  cin >> n >> m;

  vector<ll> a(n), b(m);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int j = 0; j < m; j++) {
    cin >> b[j];
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  vector<ll> spA = buildSP(a);
  vector<ll> spB = buildSP(b);

  ll kmax = min({(ll)n, (ll)m, (ll)((n + (ll)m) / 3)});

  cout << kmax << '\n';
  if (kmax == 0)
    return;

  vector<ll> fvals(kmax + 1, 0LL);
  for (ll k = 1; k <= kmax; k++) {
    ll best = 0;
    ll startX = max(0LL, 2 * k - m);
    ll endX = min(k, (ll)(n - k));
    startX = max(startX, 0LL);
    endX = max(endX, 0LL);
    endX = min(endX, (ll)spA.size() - 1);

    for (ll x = startX; x <= endX && x <= k; x++) {
      ll y = k - x;
      if (y < 0 || y >= (ll)spB.size())
        continue;
      if (2 * x + y <= n && x + 2 * y <= m) {
        ll cur = spA[x] + spB[y];
        if (cur > best)
          best = cur;
      }
    }
    fvals[k] = best;
  }

  for (int k = 1; k <= kmax; k++) {
    cout << fvals[k] << " ";
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
*/

// the below is optimised. we turns the inside linear search for best // x to
// maximize spA[x] + spB[k-x] to a ternanry search
//

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> buildSP(const vector<ll> &v) {
  int n = (int)v.size();
  int xMax = n / 2;
  vector<ll> sp(xMax + 1, 0LL);
  for (int i = 1; i <= xMax; i++) {
    ll gap = v[n - i] - v[i - 1];
    sp[i] = sp[i - 1] + gap;
  }
  return sp;
}

ll cVal(const vector<ll> &spA, const vector<ll> &spB, ll k, ll x) {
  if (x < 0 || x >= (ll)spA.size())
    return -1;
  ll y = k - x;
  if (y < 0 || y >= (ll)spB.size())
    return -1;
  return spA[x] + spB[y];
}

ll ternarySearchMax(const vector<ll> &spA, const vector<ll> &spB, ll k, ll L,
                    ll R) {
  ll lo = L, hi = R;
  ll best = 0;
  while (hi - lo >= 3) {
    ll mid1 = lo + (hi - lo) / 3;
    ll mid2 = hi - (hi - lo) / 3;
    ll val1 = cVal(spA, spB, k, mid1);
    ll val2 = cVal(spA, spB, k, mid2);
    if (val1 < val2) {
      lo = mid1 + 1;
    } else {
      hi = mid2 - 1;
    }
  }
  for (ll x = lo; x <= hi; x++) {
    ll tmp = cVal(spA, spB, k, x);
    if (tmp > best)
      best = tmp;
  }
  return best;
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<ll> a(n), b(m);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int j = 0; j < m; j++) {
    cin >> b[j];
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  vector<ll> spA = buildSP(a);
  vector<ll> spB = buildSP(b);

  ll kmax = min({(ll)n, (ll)m, (ll)((n + (ll)m) / 3)});
  cout << kmax << "\n";
  if (kmax == 0)
    return;

  vector<ll> fvals(kmax + 1, 0LL);
  for (ll k = 1; k <= kmax; k++) {

    ll L = max(0LL, 2 * k - (ll)m);
    ll R = min(k, (ll)n - k);
    L = max(L, 0LL);
    R = max(R, 0LL);
    L = min(L, (ll)spA.size() - 1);
    R = min(R, (ll)spA.size() - 1);
    if (L <= R) {
      fvals[k] = ternarySearchMax(spA, spB, k, L, R);
    }
  }
  for (ll k = 1; k <= kmax; k++) {
    cout << fvals[k] << " ";
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
