#include <bits/stdc++.h>
using namespace std;

const pair<int,int> dxy[] = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1},
};

bool processed[20][20][4][20][20][4];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    ifstream cin ("cownav.in");
    ofstream cout ("cownav.out");
    
    int N; cin >> N;
    
    vector<string> g(N); for (auto& row : g) cin >> row;
    reverse(g.begin(), g.end());
    
    queue<tuple<int, tuple<int, int, int>, tuple<int, int, int> > > q;
    
    q.push({0, {0, 0, 0}, {0, 0, 1}});
    
    while (!q.empty()) {
        auto [moves, pos1, pos2] = q.front();
        q.pop();
        auto [r1, c1, d1] = pos1;
        auto [r2, c2, d2] = pos2;
        
        if (processed[r1][c1][d1][r2][c2][d2]) continue;
        processed[r1][c1][d1][r2][c2][d2] = true;
        
        if (min({r1, c1, r2, c2}) == N-1) {
            cout << moves << '\n';
            return 0;
        }
        
        q.push({moves + 1, {r1, c1, (d1+1)%4}, {r2, c2, (d2+1)%4}});
        q.push({moves + 1, {r1, c1, (d1+3)%4}, {r2, c2, (d2+3)%4}});
        
        auto [dy, dx] = dxy[d1];
        int R1 = clamp(r1 + dy, 0, N-1);
        int C1 = clamp(c1 + dx, 0, N-1);
        if (min(r1, c1) == N - 1 || g[R1][C1] == 'H') R1 = r1, C1 = c1;
        
        tie(dy, dx) = dxy[d2];
        int R2 = clamp(r2 + dy, 0, N-1);
        int C2 = clamp(c2 + dx, 0, N-1);
        if (min(r2, c2) == N - 1 || g[R2][C2] == 'H') R2 = r2, C2 = c2;
        
        q.push({moves + 1, {R1, C1, d1}, {R2, C2, d2}});
    }
    
    assert(false);
    
    return 0;
}
