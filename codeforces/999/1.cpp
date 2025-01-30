#include <bits/stdc++.h> 
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;

    int oddcnt = 0;
    int evencnt = 0;

    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
        if(v[i] & 1) oddcnt++;
        else evencnt++;
    }

    
    cout << (evencnt >0  ?  oddcnt+1: oddcnt-1) << '\n';
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


