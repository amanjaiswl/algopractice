#include <bits/stdc++.h> 
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    
    for (int i = 0; i < n - 1; i++){
        if (v[i] <= v[i + 1]) {
            v[i + 1] -= v[i];
            v[i] = 0;
        }
    }

    
    bool flag = true;
    for (int i = 0; i < n - 1; i++){
        if (v[i] > v[i + 1]) {
            flag = false;
            break;
        }
    }

    cout << (flag ? "YES\n" : "NO\n");
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}


