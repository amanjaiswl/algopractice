#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    ll ans = 4 * m;  
    n--;  
    int x, y;
    cin >> x >> y;
    while (n--) {
        cin >> x >> y;
        int a = abs(m - x);  
        int b = abs(m - y);  
        ans = (ans + 4 * m) - (2 * (a + b));
    }

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

