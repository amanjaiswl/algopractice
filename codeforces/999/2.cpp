#include <bits/stdc++.h> 
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i= 0 ; i < n; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    int x;
    int j = -1;
    for(int i=n-2; i>=0; i--){
        if(v[i] == v[i+1]){
            j = i;
            x = v[i];
            break;
        }
    }

    if(j == -1){
        cout << "-1\n";
        return;
    }

    v.erase(v.begin() + j);
    v.erase(v.begin() + j);
    
    for(int i=0; i<n-3; i++){
        if(v[i] + 2*x > v[i+1]){
            cout << v[i] << " " << v[i+1] << " " << x << " " << x << '\n';
            return;
        }
    }

    cout << "-1\n";

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


