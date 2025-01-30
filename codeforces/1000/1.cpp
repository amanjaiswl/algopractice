#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<vector<int>> adj(n + 1);
    vector<int> degree(n + 1, 0);
    
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }
    
    // Create a list of vertices sorted by degree descending
    vector<pair<int, int>> degVertex;
    for (int i = 1; i <= n; ++i) {
        degVertex.emplace_back(degree[i], i);
    }
    sort(degVertex.begin(), degVertex.end(), greater<>());
    
    // Keep track of the highest two degrees
    int d1 = degVertex[0].first;
    int v1 = degVertex[0].second;
    int d2 = 0, v2 = -1;
    for (int i = 1; i < n; ++i) {
        if (degVertex[i].first >= d2) {
            d2 = degVertex[i].first;
            v2 = degVertex[i].second;
        }
    }
    
    long long candA = 0, candB = 0, candC = d1 + d2 - 2; 
    
    // For Case A: try to find best nonadjacent to v1
    {
        // Mark neighbors of v1
        vector<bool> isNeighbor(n + 1, false);
        for (int neigh : adj[v1]) {
            isNeighbor[neigh] = true;
        }
        isNeighbor[v1] = true; // also mark v1 itself
        
        // Look for highest degree vertex not adjacent to v1
        for (auto &p : degVertex) {
            int deg = p.first;
            int vertex = p.second;
            if (!isNeighbor[vertex]) {
                candA = (long long)d1 + deg - 1;
                break;
            }
        }
    }
    
    // For Case B: try to find best nonadjacent to v2
    {
        if (v2 != -1) { // if we found v2
            vector<bool> isNeighbor(n + 1, false);
            for (int neigh : adj[v2]) {
                isNeighbor[neigh] = true;
            }
            isNeighbor[v2] = true;
            
            for (auto &p : degVertex) {
                int deg = p.first;
                int vertex = p.second;
                if (!isNeighbor[vertex]) {
                    candB = (long long)d2 + deg - 1;
                    break;
                }
            }
        }
    }
    
    long long result = max({candA, candB, (long long)candC});
    cout << result << "\n";
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

