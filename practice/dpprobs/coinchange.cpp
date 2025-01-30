#include <bits/stdc++.h> 
// Find the minimum number of coins needed to make up the amount A
using namespace std;

using ll = long long;

void solve(){
    vector<int> v = {1,2,3,4,5,10,20,100};
    int target = 35;
    //int max_el = *max_element(v.begin(), v.end());

    vector<int> dp(target + 1, 1e9);
    dp[0] = 0;
    
    vector<int> choice(target+1, -1);
    for(int i=1; i<= target; i++){
        for(int coin : v){
            
                if(coin <= i && dp[i - coin] +1 < dp[i]){

                 dp[i] = dp[i- coin]+1;
                 choice[i] = coin;
                }
        }
    }

    if(dp[target] <= 1e9) cout << " min num of coins : " << dp[target] << '\n';
    else cout << "not possible" <<'\n';

    cout << "the coins are : ";
    
    int amount = target;
    while(amount >0  && choice[amount] != -1){
        cout << choice[amount] << " ";
        amount -= choice[amount];
    }
        

    cout <<'\n';
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


