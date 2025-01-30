// https://codeforces.com/contest/455/problem/A

#include <bits/stdc++.h> 

using namespace std;

using ll = long long;

void solve(){
    int n;
    cin >> n;

    const int MAX_VAL = 100000;

    vector<ll> freq(MAX_VAL + 1,0);
    int max_el = -1;
    for(int i=0 ; i<n; i++){
        int x;
        cin >> x;
        if(x > max_el) max_el = x;
        freq[x]++;
        
    }

    vector<ll> dp(max_el +1, 0);
    dp[0] = 0;
    dp[1] = freq[1];

    for(int i=2; i<= max_el; i++)
        dp[i] = max(dp[i-1], dp[i-2] + freq[i] * i);

    cout << dp[max_el] << '\n';

        



}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
        solve();

    return 0;
}


