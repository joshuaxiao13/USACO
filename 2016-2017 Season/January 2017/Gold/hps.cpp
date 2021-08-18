#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    ifstream cin ("hps.in");
    ofstream cout ("hps.out");
    
    int N, K; cin >> N >> K;

    vector<char> FJ(N); for (auto& x : FJ) cin >> x;
    
    auto win = [&](char fj, int bessie) {
        return bessie == 0 && fj == 'S' || bessie == 1 && fj == 'P' || bessie == 2 && fj == 'H';
    };
    
    vector<vector<vector<int> > > dp(N, vector<vector<int> >(K+1, vector<int>(3, 0)));
    
    int ans = 0;
    
    for (int i = 0; i < N; ++i) {
        for (int k = 0; k <= min(i, K); ++k) {
            for (int move = 0; move < 3; ++move) {
                if (i > 0) dp[i][k][move] = dp[i-1][k][move];
                int point = win(FJ[i], move);
                dp[i][k][move] += point;
                if (k > 0) {
                    for (int prev = 0; prev < 3; ++prev) {
                        if (prev == move) continue;
                        dp[i][k][move] = max(dp[i][k][move], dp[i][k-1][prev] + point);
                    }
                }
                if (i == N - 1) ans = max(ans, dp[i][k][move]);
            }
        }
    }
    
    cout << ans << '\n';
    
    return 0;
}
