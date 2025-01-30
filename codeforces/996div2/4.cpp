#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

void solve() {
    int n, k, l;
    cin >> n >> k >> l;

    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int low = 0;
    int high = 1e9;

    auto distance_coverage = [&] (int t) {
        if(t < 2 * v[0]) 
            return 0;

        int remaining = t - 2 * v[0];

        for(int i = 0; i < n; i++) {
            if(remaining >= 2 * v[i] - t) {
                remaining = min(remaining, 2 * v[i] + t) + 2 * k;
            }
        }

        return remaining;
    };

    
    while(low < high) {
        int mid = low + (high - low) / 2;
        if(distance_coverage(mid) >= 2 * l) {
            high = mid;  
        } else {
            low = mid + 1;  
        }
    }

    cout << low << '\n';
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}

