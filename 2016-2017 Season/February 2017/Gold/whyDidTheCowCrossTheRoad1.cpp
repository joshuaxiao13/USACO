#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const pair<int, int> dxy[] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}
};

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    ifstream cin ("visitfj.in");
    ofstream cout ("visitfj.out");
    
    int N, T; cin >> N >> T;
    
    vector<vector<int> > grass(N, vector<int>(N));
    
    for (auto& row : grass) for (auto& x : row) cin >> x;
    
    priority_queue<tuple<int, int, pair<int, int> > > pq;
    
    vector<vector<vector<int> > > best(N, vector<vector<int> >(N, vector<int>(3, INF)));
    vector<vector<vector<bool> > > processed(N, vector<vector<bool> >(N, vector<bool>(3, false)));
    
    best[0][0][0] = 0;
    pq.push({0, 0, {0, 0}});
    
    auto valid = [&](int r, int c) {
        return min(r, c) >= 0 && max(r, c) < N;
    };
    
    while (!pq.empty()) {
        auto [ignore, mod, pos] = pq.top();
        auto [r, c] = pos;
        pq.pop();
        if (processed[r][c][mod]) continue;
        processed[r][c][mod] = true;
        for (auto [dx, dy] : dxy) {
            int R = r + dy;
            int C = c + dx;
            if (valid(R, C) && !processed[R][C][(mod+1)%3]) {
                int cost = best[r][c][mod] + T;
                if (mod == 2) cost += grass[R][C];
                if (best[R][C][(mod+1)%3] > cost) {
                    best[R][C][(mod+1)%3] = cost;
                    pq.push({-best[R][C][(mod+1)%3], (mod + 1) % 3, {R, C}});
                }
            }
        }
    }
    
    cout << min({best[N-1][N-1][0], best[N-1][N-1][1], best[N-1][N-1][2]}) << '\n';
    
    return 0;
}
