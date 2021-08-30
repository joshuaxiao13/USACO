#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5;
int N, M, inDegree[mxN];
vector<pair<int, int>> adj[mxN];

// topological sort with Kahn's algorithm
bool valid(int X) {
    memset(inDegree, 0, sizeof inDegree);
    for (int u  = 0; u < N; ++u) {
        for (auto [x, v] : adj[u]) {
            if (x <= X) ++inDegree[v];
        }
    }
    queue<int> q;
    int cnt = N;
    for (int u = 0; u < N; ++u) {
        if (inDegree[u] == 0) {
            q.push(u);
            --cnt;
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto [x, v] : adj[u]) {
            if (x <= X && --inDegree[v] == 0) {
                q.push(v);
                --cnt;
            }
        }
    }
    return cnt == 0;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);
    
    cin >> N >> M;
    
    for (int i = 0; i < M; ++i) {
        int m; cin >> m;
        vector<int> cow(m); for (auto& x : cow) cin >> x, --x;
        for (int j = 0; j < m-1; ++j) {
            adj[cow[j]].push_back({i, cow[j+1]});
        }
    }
    
    int X = -1;
    
    for (int k = M; k > 0; k /= 2) {
        while (X + k < M && valid(X + k)) {
            X += k;
        }
    }
    
    memset(inDegree, 0, sizeof inDegree);
    
    for (int u  = 0; u < N; ++u) {
        for (auto [x, v] : adj[u]) {
            if (x <= X) ++inDegree[v];
        }
    }
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (int u = 0; u < N; ++u) {
        if (inDegree[u] == 0) pq.push(u);
    }
    
    int cnt = N;
    
    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        --cnt;
        cout << u + 1;
        if (cnt != 0) cout << ' ';
        for (auto [x, v] : adj[u]) {
            if (x <= X && --inDegree[v] == 0) {
                pq.push(v);
            }
        }
    }
    
    cout << '\n';
    
    return 0;
}
