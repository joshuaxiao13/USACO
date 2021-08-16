#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> root;
    DSU(int n) { root = vector<int>(n, -1); };
    int find(int u) {
        if (root[u] < 0) return u;
        return root[u] = find(root[u]);
    }
    bool same(int u, int v) {
        return find(u) == find(v);
    }
    bool unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return false;
        if (root[u] < root[v]) swap(u, v);
        root[u] = v;
        root[v] = min(root[v], root[u] - 1);
        return true;
    }
};

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    ifstream cin ("closing.in");
    ofstream cout ("closing.out");

    int N, M; cin >> N >> M;
    
    vector<pair<int, int> > edge(M);
    
    for (auto& [u, v] : edge) cin >> u >> v, --u, --v;
    
    vector<int> p(N); for (auto& x : p) cin >> x, --x;
    
    vector<int> rank(N); 
    for (int i = 0; i < N; ++i) rank[p[i]] = i;

    vector<int> adj[N];
    
    while (M--) {
        int u, v;
        tie(u, v) = edge[M];
        if (rank[u] > rank[v]) swap(u, v);
        adj[u].push_back(v);
    }
    
    vector<string> ans;

    DSU dsu(N);
    int components = N;
    
    for (int i = N - 1; i >= 0; --i) {
        int u = p[i];
        assert(u < N);
        for (auto v : adj[u]) {
            if (dsu.unite(u, v)) {
                --components;
            }
        }
        ans.push_back(i + 1 == components ? "YES" : "NO");
    }
    
    reverse(ans.begin(), ans.end());
    
    for (auto x : ans) cout << x << '\n';

    return 0;
}
