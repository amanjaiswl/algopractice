#include <bits/stdc++.h> 
// number of ways to achieve target by uniquely combining the coins 
using namespace std;

using ll = long long;

void solve(){
    vector<int> v = {1,2,3,4,5,10,20,100};
    int target = 35;

    vector<int> dp(target+1, 0);
    dp[0] = 1;

    for(int coin : v){
        for(int i=coin;i <= target; i++)
            dp[i] += dp[i-coin];
    }

    cout << "you can make " << target << " uniquely in " << dp[target] << " ways" <<'\n';


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


