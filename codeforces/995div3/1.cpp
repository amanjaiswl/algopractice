#include <bits/stdc++.h> 

using namespace std;

using ll = long long;

void solve(){
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);

    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;

    vector<vector<ll>> dp(n, vector<ll>(2,-1e9));

    dp[0][0] = 0;
    dp[0][1] = a[0];

    for(int i=1 ; i<n ;i++){
        dp[i][0] = max(dp[i-1][0], dp[i-1][1] - b[i]);
        dp[i][1] = max(dp[i-1][0] + a[i], dp[i-1][1] + a[i] - b[i] );
    }

    cout << max(dp[n-1][0] , dp[n-1][1]) << '\n';

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


