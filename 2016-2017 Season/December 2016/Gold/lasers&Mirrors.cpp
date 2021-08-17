#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    ifstream cin ("lasers.in");
    ofstream cout ("lasers.out");
    
    int N, x_start, y_start, x_end, y_end;
    
    cin >> N >> x_start >> y_start >> x_end >> y_end;
    
    unordered_map<int, vector<int>> mx, my;
    vector<pair<int, int> > mirror(N);

    for (int i = 0; i < N; ++i) {
        auto& [x, y] = mirror[i];
        cin >> x >> y;
        mx[x].push_back(i);
        my[y].push_back(i);
    }
    
    queue<tuple<int, int,int> > q;
    
    q.push({-1, 0, 0});
    q.push({-1, 0, 1});
    
    while (!q.empty()) {
        auto [i, cost, dir] = q.front();
        q.pop();
        if (dir == 0) {
            int x = i == -1 ? x_start : mirror[i].first;
            if (x == x_end) {
                cout << cost << '\n';
                return 0;
            }
            for (auto j : mx[x]) {
                if (j != i) q.push({j, cost + 1, 1});
            }
            mx[x].clear();
        } else {
            int y = i == -1 ? y_start : mirror[i].second;
            if (y == y_end) {
                cout << cost << '\n';
                return 0;
            }
            for (auto j : my[y]) {
                if (j != i) q.push({j, cost + 1, 0});
            }
            my[y].clear();
        }
    }
    
    cout << "-1\n";

    return 0;
}
