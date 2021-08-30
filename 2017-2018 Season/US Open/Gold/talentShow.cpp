#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int mxN = 250001;
int dp[mxN];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    freopen("talent.in", "r", stdin);
    freopen("talent.out", "w", stdout);
    
    int N, W; cin >> N >> W;
    
    for (auto& x : dp) x = INF;
    dp[0] = 0;
    
    int ans = 0;
    
    while (N--) {
        int w, t;
        cin >> w >> t;
        for (int talent = mxN; talent >= t; --talent) {
            if (dp[talent-t] < INF) {
                dp[talent] = min(dp[talent], dp[talent-t] + w);
                if (dp[talent] >= W) {
                    ans = max(ans, 1000*talent/dp[talent]);
                }
            }
        }
    }
    
    cout << ans << '\n';
    
    return 0;
}
