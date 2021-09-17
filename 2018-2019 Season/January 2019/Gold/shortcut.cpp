#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    freopen ("shortcut.in", "r", stdin);
    freopen ("shortcut.out", "w", stdout);
    
    int N, M, T; cin >> N >> M >> T;
    
    vector<ll> pass(N); for (auto& x : pass) cin >> x;
    
    vector<pair<int, ll>> adj[N];
    
    for (int i = 0; i < M; ++i) {
        int u, v, t; cin >> u >> v >> t;
        --u, --v;
        adj[u].push_back({v, t});
        adj[v].push_back({u, t});
    }
    
    vector<ll> best(N, INF), go(N, 0);
    vector<bool> processed(N, false);
    
    priority_queue<tuple<ll, int, int>> pq;
    best[0] = 0;
    pq.push({0, 1, 0});
    
    stack<int> stk;
    
    while (!pq.empty()) {
        auto [cost, prevField, u] = pq.top();
        pq.pop();
        if (processed[u]) continue;
        processed[u] = true;
        go[u] = -prevField;
        if (u != 0) stk.push(u);
        for (auto [v, w] : adj[u]) {
            if (!processed[v] && best[u] + w <= best[v]) {
                best[v] = best[u] + w;
                pq.push({-best[v], -u, v});
            }
        }
    }
    
    while (!stk.empty()) {
        pass[go[stk.top()]] += pass[stk.top()];
        stk.pop();
    }
    
    ll ans = 0;
    
    for (int i = 1; i < N; ++i) {
        ans = max(ans, pass[i] * (best[i] - T));
    }

    cout << ans << '\n';

    return 0;
}
