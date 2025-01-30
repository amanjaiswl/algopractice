#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

#define ll long long

void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    int cnt = 0;
    int idx = -1; 

    
    for (int i = 0; i < n; ++i) {
        if(a[i] < b[i]) {
            cnt++;
            idx = i;
        }
    }
    
    
    if(cnt  > 1) {
        cout << "NO\n";
        return;
    }
    
    
    if(cnt  == 0) {
        cout << "YES\n";
        return;
    }
    
    
    int needed = b[idx] - a[idx];
    
    
    for (int j = 0; j < n; ++j) {
        if(j == idx) continue;  
        if(a[j] - b[j] < needed) {
            cout << "NO\n";
            return;
        }
    }
    
    cout << "YES\n";
}


int main(){
  int t;
  cin >> t;
  while (t--){
    solve();
  }
  return 0;
}


