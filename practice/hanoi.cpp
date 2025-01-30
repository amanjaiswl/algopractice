#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void printmove(int start, int end) { cout << start << " --> " << end << '\n'; }

int hanoi(int n, int start, int end) {
  if (n == 1) {
    printmove(start, end);
    return 1;
  }

  int other = 6 - (start + end);
  int moves = 0;
  moves += hanoi(n - 1, start, other);
  printmove(start, end);
  moves++;
  moves += hanoi(n - 1, other, end);

  return moves;
}

void solve() {

  int n = 5;
  int start = 1;
  int end = 2;

  int totalmoves = hanoi(5, start, end);
  cout << "total moves: " << totalmoves << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;

  while (t--) {
    solve();
  }
  return 0;
}
