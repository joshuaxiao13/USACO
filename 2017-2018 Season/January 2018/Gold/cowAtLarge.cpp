#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5;
vector<int> adj[mxN];
int dist[mxN];
bool vis[mxN];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    freopen("atlarge.in", "r", stdin);
    freopen("atlarge.out", "w", stdout);

    int N, K; cin >> N >> K, --K;
    
    for (int i = 0; i < N-1; ++i) {
        int u, v; cin >> u >> v, --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    queue<int> q1;
    queue<pair<int, int>> q2;
    
    vis[K] = true;
    q1.push(K);
    
    while (!q1.empty()) {
        int u = q1.front(); q1.pop();
        bool isExit = true;
        for (auto v : adj[u]) {
            if (!vis[v]) {
                dist[v] = dist[u] + 1;
                vis[v] = true;
                q1.push(v);
                isExit = false;
            }
        }
        if (isExit) q2.push({u, 0});
    }
    
    memset(vis, false, sizeof(vis));
    
    int ans = q2.size();

    while (!q2.empty()) {
        auto [u, d] = q2.front(); q2.pop();
        if (d <= dist[u]) {
            if (vis[u]) {
                --ans;
                continue;
            }
            vis[u] = true;
            for (auto v : adj[u]) {
                if (!vis[v]) q2.push({v, d + 1});
            }
        }
    }
    
    cout << ans << '\n';

    return 0;
}
