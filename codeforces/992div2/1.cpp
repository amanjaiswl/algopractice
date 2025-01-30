#include <bits/stdc++.h> 

using namespace std;

#define ll long long

void solve(){
    int n, k;
    cin >> n >> k;

    unordered_map<int, int> freq;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
        int rem = v[i] %k;
        freq[rem]++;
    }

    int idx = -1;
    for(int i=0 ; i<n; i++){
        int rem = v[i] %k;
        if(freq[rem] == 1){
            idx = i+1;
            break;
        }
    }

    if(idx == -1) cout << "NO\n";
    else cout << "YES\n" << idx << '\n';
}

int main(){
  int t;
  cin >> t;
  while (t--){
    solve();
  }
  return 0;
}


