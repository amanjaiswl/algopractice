#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

void solve(){
    int n;
    cin >> n;
    vector<ll> v(n+1);
    for(int i=1;i<=n;i++){
        cin >> v[i];
    }
    vector<ll> dp(n+1,0);
    dp[0]=1;

    for(int i=1; i<=n; i++){
        if(i-1 >= 0){
            ll x = (i-1 ==0 ? 0 : v[i-1]);
            if(v[i] == x) dp[i] = (dp[i] + dp[i-1]) % MOD;
        }
        if(i-2 >= 0){
            ll x = (i-2 == 0 ? 0 : v[i-2]);
            if(v[i] == x+1 ) dp[i]= (dp[i] + dp[i-2]) % MOD;
        }
    }
    ll ans = (dp[n] + dp[n-1]) % MOD;
    cout<< ans <<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

