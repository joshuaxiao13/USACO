#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    ifstream cin ("checklist.in");
    ofstream cout ("checklist.out");
    
    int H, G; cin >> H >> G;
    
    vector<vector<pair<int, int> > > cow(2);
    cow[0].resize(H);
    cow[1].resize(G);
    
    for (auto& [x, y] : cow[0]) cin >> x >> y;
    for (auto& [x, y] : cow[1]) cin >> x >> y;
        
    auto distance = [&](pair<int, int> a, pair<int, int> b) {
        int dx = a.first - b.first;
        int dy = a.second - b.second;
        return dx * dx + dy * dy;
    };
    
    vector<vector<vector<ll> > > dp(H + 1, vector<vector<ll> >(G + 1, vector<ll>(2, INF)));
    
    for (int i = 0; i <= H; ++i) {
        for (int j = 0; j <= G; ++j) {
            for (int k = 0; k < 2; ++k) {
                if ((i == 0 && k == 0) || (j == 0 && k == 1)) continue; 
                if (i == 1 && j == 0 && k == 0) dp[i][j][k] = 0;
                if (i < H) {
                    ll cost = k == 0 ? distance(cow[0][i-1], cow[0][i]) : distance(cow[1][j-1], cow[0][i]);
                    dp[i+1][j][0] = min(dp[i+1][j][0], dp[i][j][k] + cost);
                }
                if (j < G) {
                    ll cost = k == 0 ? distance(cow[0][i-1], cow[1][j]) : distance(cow[1][j-1], cow[1][j]);
                    dp[i][j+1][1] = min(dp[i][j+1][1], dp[i][j][k] + cost);
                }
            }
        }
    }
    
    cout << dp[H][G][0] << '\n';
    
    return 0;
}
