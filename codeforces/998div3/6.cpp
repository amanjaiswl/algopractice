#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 998244353;
const int KMAX = 100000;
const int RMAX = 17;

static int dp[RMAX+1][KMAX+1];

void buildDP() {
    for(int x = 2; x <= KMAX; x++)
        dp[1][x] = 1;
    
    for(int r = 2; r <= RMAX; r++){
        for(int x = 2; x <= KMAX; x++){
            int ways = dp[r-1][x];
            if(ways == 0) continue;
            for(ll m = 2; m*x <= KMAX; m++){
                int nxt = (int)(m*x);
                dp[r][nxt] = (dp[r][nxt] + ways) % MOD;
            }
        }
    }
}

ll modexp(ll base, ll exp){
    ll result = 1 % MOD;
    base %= MOD;
    while(exp > 0){
        if(exp & 1) result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

static ll fact[40], invFact[40];

void Factorials(){
    fact[0] = 1;
    for(int i = 1; i < 40; i++){
        fact[i] = (fact[i-1] * i) % MOD;
    }
    invFact[39] = modexp(fact[39], MOD-2);
    for(int i = 38; i >= 0; i--){
        invFact[i] = (invFact[i+1]*(i+1)) % MOD;
    }
}

ll comb(ll n, int r){
    if(r > n || r < 0) return 0;
    ll num = 1;
    for(int i = 0; i < r; i++){
        num = (num * ((n - i) % MOD)) % MOD;
    }
    ll den = fact[r];
    ll invDen = modexp(den, MOD-2);
    ll ans = (ll)(num % MOD);
    ans = (ans * invDen) % MOD;
    return ans;
}

void solve(){
    ll n;
    int k;
    cin >> k >> n;

    vector<ll> ans(k, 0LL);
    ans[0] = n % MOD;

    int limitR = (int)min((long long)RMAX, n);
    for(int x = 2; x <= k; x++){
        ll sum_ways = 0;
        for(int r = 1; r <= limitR; r++){
            int ways = dp[r][x];
            if(ways == 0) continue;
            ll c = comb(n+1, r+1);
            ll cur = (1LL * ways * c) % MOD;
            sum_ways = (sum_ways + cur) % MOD;
        }
        ans[x-1] = sum_ways;
    }

    for(int i = 0; i < k; i++){
        cout << ans[i] << " ";
    }

    cout << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    buildDP();
    Factorials();

    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}

