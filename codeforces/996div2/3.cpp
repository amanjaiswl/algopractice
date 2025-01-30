#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

#define ll long long

void solve(){
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    vector<vector<ll>> v(n, vector<ll> (m) );

    for(int i= 0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> v[i][j];
        }
    }

    vector<ll> rowsum(n);
    vector<ll> colsum(m);

    for(int i= 0; i<n; i++){
        for(int j=0; j<m; j++){
            rowsum[i] += v[i][j];
            colsum[j] += v[i][j];
        }
    }

    

    int x= 0;
    int y =0;
    int cnt = 0;
    

    while(cnt < n + m -1){
        if(s[cnt] == 'D'){
            v[x][y] = -rowsum[x];
            rowsum[x] += v[x][y];
            colsum[y] += v[x][y];
            x++;
        }
        else{
            v[x][y] = -colsum[y];
            rowsum[x] += v[x][y];
            colsum[y] += v[x][y];
            y++;
        }
        cnt++;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << v[i][j] << " ";
        }
        cout << '\n';
    }


}

int main(){
  int t;
  cin >> t;
  while (t--){
    solve();
  }
  return 0;
}


