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
    int size(int u) { return -root[find(u)]; };
};

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);
    
    int N, B; cin >> N >> B;
    
    priority_queue<pair<int, int>> pq;
    vector<tuple<int, int, int>> boot;
    
    for (int i = 0; i < N; ++i) {
        int f; cin >> f;
        pq.push({f, i});
    }
    
    for (int i = 0; i < B; ++i) {
        int s, d; cin >> s >> d;
        boot.push_back({s, d, i});
    }
    
    sort(boot.rbegin(), boot.rend());
    
    vector<int> ans(B);
    
    DSU dsu(N);
    int mx = 0;
    vector<bool> active(N, false);
    
    for (auto [s, d, id] : boot) {
        while (!pq.empty() && pq.top().first > s) {
            auto [f, u] = pq.top();
            pq.pop();
            active[u] = true;
            if (u > 0 && active[u-1]) dsu.unite(u-1, u);
            if (u < N-1 && active[u+1]) dsu.unite(u, u+1);
            mx = max(mx, dsu.size(u));
        }
        ans[id] = mx < d;
    }
    
    for (auto x : ans) cout << x << '\n';

    return 0;
}
