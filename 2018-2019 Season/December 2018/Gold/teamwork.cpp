#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false); 
    
    freopen ("teamwork.in", "r", stdin);
    freopen ("teamwork.out", "w", stdout);

    int N, K; cin >> N >> K;
    
    vector<int> skill(N), dp(N, 0);
    for (auto& x : skill) cin >> x;
    
    for (int i = 0; i < N; ++i) {
        int mx = 0;
        for (int size = 0; size <= min(i, K-1); ++size) {
            mx = max(mx, skill[i-size]);
            dp[i] = max(dp[i], mx * (size + 1) + (i > size ? dp[i-size-1] : 0));
        }
    }
    
    cout << dp[N-1] << '\n';

    return 0;
}
