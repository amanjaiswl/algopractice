#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    long long sumA = 0, sumB = 0;
    long long maxA = 0, maxB = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sumA += a[i];
      maxA = max(maxA, a[i]);
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i];
      sumB += b[i];
      maxB = max(maxB, b[i]);
    }

    // If sumA < sumB, it's impossible.
    if (sumA < sumB) {
      cout << -1 << "\n";
      continue;
    }

    // If the sums are equal, then a mod k = a must hold for all a,
    // so every a must be less than k and hence b equals a (as multisets).
    if (sumA == sumB) {
      vector<long long> sortedA = a, sortedB = b;
      sort(sortedA.begin(), sortedA.end());
      sort(sortedB.begin(), sortedB.end());
      if (sortedA == sortedB) {
        // We can pick any k > max(a); here we choose max(a) + 1.
        cout << maxA + 1 << "\n";
      } else {
        cout << -1 << "\n";
      }
      continue;
    }

    // Now, let X = sumA - sumB (> 0). For any valid k we have:
    // sumA - sumB = k * (some integer),
    // so k must be a divisor of X.
    long long X = sumA - sumB;
    vector<long long> divs;
    for (long long d = 1; d * d <= X; d++) {
      if (X % d == 0) {
        divs.push_back(d);
        if (d * d != X)
          divs.push_back(X / d);
      }
    }
    sort(divs.begin(), divs.end());

    // The candidate k must be > max(b). Also note that if k > max(a),
    // then every a < k and a mod k = a; but then sumA would equal sumB.
    // So we require k <= max(a).
    long long ans = -1;
    for (auto k : divs) {
      if (k <= maxB)
        continue;
      if (k > maxA)
        continue;
      if (k > 1000000000LL)
        continue; // k must be at most 1e9

      vector<long long> rem(n);
      for (int i = 0; i < n; i++) {
        rem[i] = a[i] % k;
      }
      sort(rem.begin(), rem.end());
      vector<long long> sortedB = b;
      sort(sortedB.begin(), sortedB.end());
      if (rem == sortedB) {
        ans = k;
        break;
      }
    }

    cout << ans << "\n";
  }
  return 0;
}
