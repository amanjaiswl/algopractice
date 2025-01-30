#include <bits/stdc++.h> 

using namespace std;

using ll = long long;

void solve(){
    int n;
    cin >> n;
    vector<string> graph(n);
    for (int i = 0; i < n; ++i) {
        cin >> graph[i];
    }

    vector<int> v(n,1);
    for (int i = 0; i < n; ++i) {
        v[i] = i + 1;
    }

    sort(v.begin(), v.end(), [&](int a, int b) {
        if (a < b) {
            return graph[a-1][b-1] == '1';
        }
        return graph[b-1][a-1] == '0';
    });

    for (int i = 0; i < n; ++i) {
        cout << v[i] << " ";
    }

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


