#include <bits/stdc++.h> 

using namespace std;

using ll = long long;

void solve(){
    int n, a,b,c;
    cin >> n >> a >> b >> c;

    int days = n/(a+b+c);
    int remain = n % (a+b+c);
    days *= 3;
    if(remain > 0){
        days++;
        remain-=a;
    }

    if(remain>0){
        days++;
        remain-=b;
    }
    if(remain>0){
        days++;
        remain-=c;
    }

    cout << days << '\n';

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


