#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> v;
    v.reserve(n * m);

    for (int i =1; i<= n; i++) {
        for (int j = 0; j < m; j++) {
            int card;
            cin >> card;
            v.push_back({card, i});
        }
    }

    sort(v.begin(), v.end());

    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        ans[i] = v[i].second;
    }

    bool valid = true;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int index = i * n + j;
            if (v[index].second != ans[j]) {
                valid = false;
                break;
            }
        }
        if (!valid) break;
    }

    if (valid) {
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << '\n';
    } 
    else {
        cout << -1 << '\n';
    }
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

