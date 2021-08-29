#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> root;
    DSU(int n) { root = vector<int>(n, -1); }
    int find(int u) {
        if (root[u] < 0) return u;
        return root[u] = find(root[u]);
    }
    bool unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return false;
        if (root[u] < root[v]) swap(u, v);
        root[v] += root[u];
        root[u] = v;
        return true;
    }
    int size(int u) { return -root[find(u)]; }
};

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);

    int N, Q; cin >> N >> Q;
    
    priority_queue<tuple<int, int, int>> pq;
    
    for (int i = 0; i < N-1; ++i) {
        int u, v, r;
        cin >> u >> v >> r, --u, --v;
        pq.push({r, u, v});
    }

    vector<tuple<int, int, int>> query;
    
    for (int i = 0; i < Q; ++i) {
        int k, v; cin >> k >> v, --v;
        query.push_back({k, v, i});
    }
    
    sort(query.rbegin(), query.rend());
    
    DSU dsu(N);
    vector<int> ans(Q);
    
    for (auto [k, v, id] : query) {
        while (!pq.empty() && get<0>(pq.top()) >= k) {
            auto [ignore, a, b] = pq.top();
            pq.pop();
            dsu.unite(a, b);
        }
        ans[id] = dsu.size(v) - 1;
    }

    for (auto x : ans) cout << x << '\n';

    return 0;
}
