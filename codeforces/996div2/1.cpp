#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

#define ll long long

void solve(){
    int n, a,b;
    cin >> n >> a >> b;
    if((abs(a-b)-1) % 2 != 0) cout << "Yes\n";
    else cout << "No\n";

}

int main(){
  int t;
  cin >> t;
  while (t--){
    solve();
  }
  return 0;
}


