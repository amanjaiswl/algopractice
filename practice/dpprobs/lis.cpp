#include <bits/stdc++.h> 

using namespace std;

#define ll long long

void solve(){
    vector<int> v = {1,3,5,8,100,121,1,2,3,4,5,6,7,8};

    vector<int> dp(v.size(),1);
    vector<int> parent(v.size(), -1);

    for(int i=1; i<v.size(); i++){
        for(int j=0; j< i; j++){
            if(v[j] < v[i] && dp[j] + 1 > dp[i]){
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
                
        }
    }

    

    auto max_it = max_element(dp.begin(), dp.end());
    int lis_len = *max_it;
    int lis_end_idx = distance(dp.begin(), max_it);

    vector<int> lis_seq;
    int idx = lis_end_idx;

    while(idx != -1){
        lis_seq.push_back(v[idx]);
        idx = parent[idx];
    }

    reverse(lis_seq.begin(), lis_seq.end());

    cout << "lis len : " << lis_len << '\n';
    for(auto num : lis_seq)
        cout << num << " ";

    cout << '\n';

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


