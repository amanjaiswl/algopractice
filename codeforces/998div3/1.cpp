#include <bits/stdc++.h> 
using namespace std;
using ll = long long;

void solve() {
    int a1, a2, a4, a5;
    cin >> a1 >> a2 >> a4 >> a5;
    
    
    if(a4 == a1 + 2*a2 && a5 == 2*a1 + 3*a2) {
        cout << 3 << '\n';
    }
    
    else if((a4 == a1 + 2*a2) || (a5 == a1 + a2 + a4) || (a5 == 2*a4 - a2)) {
        cout << 2 << '\n';
    }
    
    else {
        cout << 1 << '\n';
    }
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


