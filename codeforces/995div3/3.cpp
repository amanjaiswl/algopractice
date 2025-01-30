#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<int> m_list(m);
    
    vector<bool> k_list(n + 1, false);

    for(int &i : m_list)  
        cin >> i;
    
    for(int i = 0; i < k; i++) {
        int q;
        cin >> q;
        k_list[q] = true;
    }

    vector<int> unknown;
    for(int q = 1; q <= n; q++) {
        if(!k_list[q]) 
            unknown.push_back(q);
    }

    string ans;
    ans.resize(m);

    if(unknown.size() == 0) {
        ans.assign(m, '1');
    } else if(unknown.size() > 1) {
        ans.assign(m, '0');
    } else {
        int x = unknown[0];
        for(int i = 0; i < m; i++) {
            if(m_list[i] == x) 
                ans[i] = '1';
            else 
                ans[i] = '0';
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    
    return 0;
}

