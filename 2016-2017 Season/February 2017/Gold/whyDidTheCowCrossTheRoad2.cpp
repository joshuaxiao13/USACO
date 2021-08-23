#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    ifstream cin ("nocross.in");
    ofstream cout ("nocross.out");

    int N; cin >> N;
    
    vector<int> a(N), b(N);
    
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x; 

    vector<vector<int> > dp(N+1, vector<int>(N+1, 0));
    
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            if (abs(a[i-1] - b[j-1]) <= 4) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
            }
        }
    }
    
    cout << dp[N][N] << '\n';

    return 0;
}
