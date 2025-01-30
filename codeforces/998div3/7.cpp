#include <bits/stdc++.h>
using namespace std;

// We'll do a global adjacency for up to 2*n, then
// run bipartite checks across multiple test cases.

static const int MAXN = 200000; // sum of n can be up to 2e5

// We will store adjacency in a vector of vectors.
// Because the maximum label is 2n, i.e. up to 400k across tests, 
// we should build adjacency fresh each test or use a global but 
// we must be careful to handle large memory. 
// We'll implement a version that builds adjacency for each test 
// and runs BFS/DFS. Then we clear it.

bool bfsCheckBipartite(int start, 
                       const vector<vector<int>>& adj, 
                       vector<int>& color) {
    queue<int>q;
    q.push(start);
    color[start] = 0;  // start coloring with 0
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : adj[u]){
            if(color[v] < 0){
                // not visited => assign opposite color
                color[v] = 1 - color[u];
                q.push(v);
            } else if(color[v] == color[u]){
                // same color => conflict => not bipartite
                return false;
            }
        }
    }
    return true;
}

void solve(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        for(int i=0; i<n; i++){
            cin >> b[i];
        }

        // Build adjacency for the values 1..2n.
        // We'll use 1-based indexing for the graph as well.
        // So adjacency has size 2n+1.
        int N = 2*n;
        vector<vector<int>> adj(N+1);

        // 1) Add consecutive edges (1--2, 2--3, ..., (2n-1)--(2n))
        for(int val=1; val < N; val++){
            adj[val].push_back(val+1);
            adj[val+1].push_back(val);
        }

        // 2) Add column edges (a[i]--b[i])
        for(int i=0; i<n; i++){
            int x = a[i], y = b[i];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        // Now run a bipartite check (coloring).
        vector<int> color(N+1, -1); 
        // -1 means uncolored, else 0 or 1

        bool isBip = true;
        for(int v=1; v<=N; v++){
            if(color[v] < 0){ 
                // not visited
                if(!bfsCheckBipartite(v, adj, color)){
                    isBip = false;
                    break;
                }
            }
        }

        cout << (isBip ? "YES\n" : "NO\n");
    }
}

int main(){
    solve();
    return 0;
}

