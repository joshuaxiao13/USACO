#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct DSU {
    vector<int> root;
    DSU(int n) { root = vector<int>(n, -1); };
    int find(int u) {
        if (root[u] < 0) return u;
        return root[u] = find(root[u]);
    }
    bool unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return false;
        if (root[u] < root[v]) swap(u, v);
        root[v] = min(root[v], root[u] - 1);
        root[u] = v;
        return true;
    }
};

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    ifstream cin ("moocast.in");
    ofstream cout ("moocast.out");
    
    int N; cin >> N;
    
    vector<pair<int, int> > cow(N);
    for (auto& [x, y] : cow) cin >> x >> y;

    auto distance = [&](int a, int b) {
      ll dx = cow[a].first - cow[b].first;
      ll dy = cow[a].second - cow[b].second;
      return dx * dx + dy * dy;
    };

    vector<tuple<ll, int, int> > edge;
    
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            edge.emplace_back(distance(i, j), i, j);
        }
    }
    
    sort(edge.begin(), edge.end());
    
    DSU dsu(N);
    int components = N;
    ll ans = 0;
    
    for (int i = 0; components > 1; ++i) {
        auto [w, u, v] = edge[i];
        if (dsu.unite(u, v)) {
            --components;
            ans = w;
        }
    }
    
    cout << ans << '\n';

    return 0;
}
