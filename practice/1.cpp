#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    ll L;
    cin >> n >> m >> L;
    
    vector<ll> hurdlesL(n), hurdlesR(n);
    for (int i = 0; i < n; ++i) {
        cin >> hurdlesL[i] >> hurdlesR[i];
    }
    
    vector<ll> powerX(m), powerV(m);
    for (int i = 0; i < m; ++i) {
        cin >> powerX[i] >> powerV[i];
    }
    
    ll currentpwr = 1;
    ll puffcnt = 0;
    bool possible = true;
    priority_queue<ll> pq;
    int pIndex = 0;
    
    for (int i = 0; i < n; ++i) {
        ll hurdleL = hurdlesL[i];
        ll hurdleR = hurdlesR[i];
        
        while (pIndex < m && powerX[pIndex] <= hurdleL - 1) {
            pq.push(powerV[pIndex]);
            pIndex++;
        }
        
        ll required = hurdleR - hurdleL + 2;
        
        while (currentpwr < required && !pq.empty()) {
            currentpwr += pq.top();
            pq.pop();
            puffcnt++;
        }
        
        if (currentpwr < required) {
            possible = false;
            break;
        }
    }
    
    cout << (possible ? puffcnt : -1) << "\n";
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

