#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct DSU {
    int n;
    vector<int> parent, rank_size;
    DSU(int n) : n(n), parent(n), rank_size(n, 0) {
        for(int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int x) {
        if(parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y) return;
        if(rank_size[x] < rank_size[y]) swap(x, y);
        parent[y] = x;
        if(rank_size[x] == rank_size[y]) rank_size[x]++;
    }
};

void solve() {

    int n, m1, m2;
    cin >> n >> m1 >> m2;

    vector<pair<int,int>> edges_f(m1), edges_g(m2);
    for(int i = 0; i < m1; i++){
        int u, v;
        cin >> u >> v;
        edges_f[i] = {u - 1, v - 1};
    }
    for(int i = 0; i < m2; i++){
        int u, v;
        cin >> u >> v;
        edges_g[i] = {u - 1, v - 1};
    }

    DSU dsu_g(n);
    for(auto &e : edges_g) {
        dsu_g.unite(e.first, e.second);
    }

    vector<int> comp(n);
    for(int v = 0; v < n; v++){
        comp[v] = dsu_g.find(v);
    }

    ll removal_cnt = 0;
    DSU dsu_f(n);
    for(auto &e : edges_f){
        int u = e.first, w = e.second;
        if(comp[u] != comp[w]) {
            removal_cnt++;
        } else {
            dsu_f.unite(u, w);
        }
    }

    vector<int> root_of(n);
    for(int i = 0; i < n; i++){
        root_of[i] = dsu_f.find(i);
    }

    unordered_map<int, vector<int>> dict;
    dict.reserve(n);
    for(int v = 0; v < n; v++){
        dict[comp[v]].push_back(root_of[v]);
    }

    ll additions = 0;
    for(auto &kv : dict){
        auto &vec_roots = kv.second;
        sort(vec_roots.begin(), vec_roots.end());
        vec_roots.erase(unique(vec_roots.begin(), vec_roots.end()), vec_roots.end());
        int x = (int)vec_roots.size();
        if(x > 1) {
            additions += (x - 1);
        }
    }

    ll ans = removal_cnt + additions;
    cout << ans << "\n";
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

