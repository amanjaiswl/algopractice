#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long a, b, ab_lim, ba_lim;
    cin >> a >> b >> ab_lim >> ba_lim;

    // Count letters.
    long long cntA = 0, cntB = 0;
    for (char c : s) {
      if (c == 'A')
        cntA++;
      else
        cntB++;
    }

    // In any valid partition, if X pairs are merged then
    // remaining singletons are cntA - X and cntB - X.
    // These must satisfy: cntA - X <= a  and  cntB - X <= b.
    long long L_bound = max({cntA - a, cntB - b, 0LL});

    // Decompose s into maximal alternating segments (where consecutive letters
    // differ). We only care about segments of length >=2 (because only they
    // allow pairing).
    vector<int> segLens;
    int n = s.size();
    for (int i = 0; i < n;) {
      int j = i;
      while (j + 1 < n && s[j + 1] != s[j])
        j++;
      int len = j - i + 1;
      if (len >= 2)
        segLens.push_back(len);
      i = j + 1;
    }

    // For segments of length exactly 2 (“S2 segments”), pairing is “rigid”.
    // For segments of length >=3, we have full flexibility.
    long long S2_count = 0; // number of segments of length 2
    long long S2_A = 0; // among S2 segments, count those that if merged yield
                        // "AB" (i.e. starting with 'A')
    long long Sg_total =
        0; // total maximum pairs available from segments of length>=3

    // (We need S2_A so we re-scan s to identify segments of length 2.)
    for (int i = 0; i < n;) {
      int j = i;
      while (j + 1 < n && s[j + 1] != s[j])
        j++;
      int len = j - i + 1;
      if (len == 2) {
        S2_count++;
        if (s[i] == 'A')
          S2_A++;
      } else if (len >= 3) {
        Sg_total += (len / 2);
      }
      i = j + 1;
    }

    long long maxPairs =
        S2_count + Sg_total; // maximum merges if we merge everywhere possible

    // Also, total merged pairs (X) must be at most (ab_lim+ba_lim)
    long long X_upper = min(maxPairs, ab_lim + ba_lim);
    if (L_bound > X_upper) {
      cout << "NO\n";
      continue;
    }

    // Now, we try to “find” a candidate total merge count X_target in [L_bound,
    // X_upper] such that it is possible to assign the AB/BA types. Write
    // X_target = X2 + Xg where:
    //   X2 (0 <= X2 <= S2_count) is the number of S2 segments we choose to
    //   merge, and Xg (0 <= Xg <= Sg_total) comes from flexible segments.
    // In an S2 segment:
    //   if merged the AB value is fixed:
    //     – if the segment is "AB": contributes 1 (we count it as “AB”),
    //     – if it is "BA": contributes 0.
    // So if we merge X2 segments (choosing some S2 segments out of S2_count)
    // then the possible total AB contribution from S2, call it Y2, can be any
    // integer between
    //    low2 = max(0, X2 - (S2_count - S2_A))
    // and
    //    high2 = min(X2, S2_A).
    // For the flexible segments, if we merge Xg pairs you can “choose” any AB
    // value between 0 and Xg. Hence, overall (with X = X2 + Xg) one may achieve
    // any AB–total in the interval
    //    [ low2, high2 + Xg ].
    // We need there to exist some AB total Y (with X - ba_lim <= Y <= ab_lim)
    // that lies in that interval. A sufficient (and after some thought,
    // necessary) condition is that:
    //      (high2 + Xg) >= (X - ba_lim)   and   low2 <= ab_lim.

    bool possible = false;
    long long upperX = X_upper;
    // We iterate over candidate X_target from L_bound to X_upper.
    for (long long X_target = L_bound; X_target <= upperX; X_target++) {
      // Case 1: if X_target can be achieved solely using flexible segments.
      if (X_target <= Sg_total) {
        // Then we can set X2 = 0 and Xg = X_target.
        // The achievable AB–total range is [0, X_target].
        // This will intersect the allowed range [X_target - ba_lim, ab_lim]
        // provided that X_target - ba_lim <= ab_lim.
        if (X_target - ba_lim <= ab_lim) {
          possible = true;
          break;
        }
      } else {
        // Case 2: we must use some S2 segments.
        // Write X_target = X2 + Xg with Xg <= Sg_total, so we must have X2 >=
        // X_target - Sg_total.
        long long minX2 = max(0LL, X_target - Sg_total);
        long long maxX2 =
            min((long long)S2_count,
                X_target); // since X2 cannot exceed S2_count nor X_target.
        // We now want there to exist an X2 in [minX2, maxX2] for which:
        // let low2 = max(0, X2 - (S2_count - S2_A)) and high2 = min(X2, S2_A).
        // With Xg = X_target - X2, the overall achievable AB–range is [ low2,
        // high2 + Xg ]. We require that (high2 + Xg) >= (X_target - ba_lim) and
        // low2 <= ab_lim.
        bool foundForThisX = false;
        // (A simple sufficient condition is to check at the “best” possible
        // choice.) Notice that if we choose X2 as small as possible then in the
        // S2 part the AB–contribution is as low as possible. In fact, if minX2
        // <= S2_A then choosing X2 = minX2 yields:
        //    high2 = minX2 and Xg = X_target - minX2.
        // Then the upper achievable AB total is minX2 + (X_target - minX2) =
        // X_target, and we need X_target >= X_target - ba_lim, which is
        // automatic. Also low2 = max(0, minX2 - (S2_count - S2_A)) which will
        // be ≤ ab_lim provided that minX2 <= ab_lim + S2_count - S2_A. So if
        // minX2 <= min(S2_A, maxX2) and minX2 <= ab_lim + S2_count - S2_A, we
        // are done.
        long long X2_lower_bound = minX2;
        long long X2_upper_bound = min(
            maxX2,
            S2_A +
                ba_lim); // we require X2 <= S2_A+ba_lim for the upper condition
        if (X2_lower_bound <= X2_upper_bound) {
          long long X2_possible_upper =
              ab_lim + S2_count - S2_A; // condition from the low2 side
          if (X2_lower_bound <= X2_possible_upper) {
            foundForThisX = true;
          }
        }
        if (foundForThisX) {
          possible = true;
          break;
        }
      }
    }

    cout << (possible ? "YES" : "NO") << "\n";
  }
  return 0;
}
