#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 50000, INF = 1e9;
vector<pair<int, int>> adj[mxN];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false); 

    freopen ("dining.in", "r", stdin);
    freopen ("dining.out", "w", stdout);

    int N, M, K; cin >> N >> M >> K;

    while (M--) {
        int u, v, t;
        cin >> u >> v >> t, --u, --v;
        adj[u].push_back({v, t});
        adj[v].push_back({u, t});
    }

    vector<int> shortestToN(N, INF), shortestPassingHaybale(N, INF);
    vector<bool> processed(N, false);
    shortestToN[N-1] = 0;
    
    priority_queue<pair<int, int>> pq;
    pq.push({0, N-1});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (processed[u]) continue;
        processed[u] = true;
        for (auto [v, t] : adj[u]) {
            if (!processed[v] && shortestToN[v] > shortestToN[u] + t) {
                shortestToN[v] = shortestToN[u] + t;
                pq.push({-shortestToN[v], v});
            }
        }
    }

    fill(processed.begin(), processed.end(), false);

    while (K--) {
        int u, y; cin >> u >> y, --u;
        if (shortestPassingHaybale[u] > shortestToN[u] - y) {
            shortestPassingHaybale[u] = shortestToN[u] - y;
            pq.push({-shortestPassingHaybale[u], u});
        }
    }

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (processed[u]) continue;
        processed[u] = true;
        for (auto [v, t] : adj[u]) {
            if (shortestPassingHaybale[v] > shortestPassingHaybale[u] + t) {
                shortestPassingHaybale[v] = shortestPassingHaybale[u] + t;
                pq.push({-shortestPassingHaybale[v], v});
            }
        }
    }

    for (int i = 0; i < N-1; ++i) {
        cout << (shortestPassingHaybale[i] <= shortestToN[i]) << '\n';
    }

    return 0;
}
