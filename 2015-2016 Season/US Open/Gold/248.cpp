#include <bits/stdc++.h>
using namespace std;

int dp[248][248];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    ifstream cin ("248.in");
    ofstream cout ("248.out");
    
    int N, ans = 1;
    
    cin >> N;
    
    for (int i = 0; i < N; ++i) {
        int x; cin >> x;
        dp[i][i] = x;
        ans = max(ans, x);
    }
    
    for (int l = N - 1; l >= 0; --l) {
        for (int r = l + 1; r < N; ++r) {
            for (int m = l; m < r; ++m) {
                if (dp[l][m] > 0 && dp[l][m] == dp[m+1][r]) {
                    dp[l][r] = dp[l][m] + 1;
                    ans = max(ans, dp[l][r]);
                    break;
                }
            }
        }
    }
    
    cout << ans << '\n';

    return 0;
}
