#include <bits/stdc++.h> 

using namespace std;

#define ll long long

void solve(){
    string a,b;
    cin >> a >> b;
    
    int n = a.size();
    int m = b.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1,0 ));

    for(int i=1; i<= n ; i++){
        for(int j=1; j<=m; j++){
            if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] +1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout << "lcs : " << dp[n][m] << '\n';

    // printing the lcs
    string lcs = "";
    int i = n;
    int j = m;

    while(i > 0 && j>0){
        if(a[i-1] == b[i-1]){
            lcs = a[i-1] + lcs;
            i--;
            j--;
        } 
        else if(dp[i-1][j] > dp[i][j-1]) i--;

        else j--;
    

    }

    cout << lcs << '\n';
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


