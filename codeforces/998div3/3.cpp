#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> v(n);
    
    for (int i = 0; i < n; i++) 
        cin >> v[i];
    
    
    sort(v.begin(), v.end());
    
    int low = 0;
    int high = n - 1;
    int ans = 0;
    
    while (low < high) {
        ll sum = v[low] + v[high];
        if (sum == k) {
            ans++;
            low++;
            high--;
        } 
        else if (sum < k)  low++; 
        else  high--;
        
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

