#include <bits/stdc++.h>
using namespace std;

bool dp[248][248][48];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    ifstream cin ("248.in");
    ofstream cout ("248.out");
    
    int N, ans = 1;
    
    cin >> N;
    
    for (int i = 0; i < N; ++i) {
        int x; cin >> x;
        dp[i][i][x] = true;
        ans = max(ans, x);
    }
    
    for (int l = N - 1; l >= 0; --l) {
        for (int r = l + 1; r < N; ++r) {
            for (int i = 2; i < 48; ++i) {
                for (int m = l; m < r; ++m) {
                    if (dp[l][m][i-1] && dp[m+1][r][i-1]) {
                        dp[l][r][i] = true;
                        ans = max(ans, i);
                        break;
                    }
                }
            }
        }
    }
    
    cout << ans << '\n';

    return 0;
}
