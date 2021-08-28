#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    freopen("spainting.in", "r", stdin);
    freopen("spainting.out", "w", stdout);
    
    int N, M, K; cin >> N >> M >> K;
    
    vector<ll> dp(N+1, 0);
    
    dp[0] = 1;
    
    ll total = 1;
    
    for (int i = 1; i <= N; ++i) {
        (total *= M) %= MOD;
        dp[i] = dp[i-1] * M % MOD;
        if (i >= K) {
            dp[i] -= dp[i-K] * (i == K ? M : M - 1) % MOD;
            if (dp[i] < 0) dp[i] += MOD;
            dp[i] %= MOD;
        }
    }
    
    ll ans = total - dp[N];
    if (ans < 0) ans += MOD;
    ans %= MOD;
    
    cout << ans << '\n';

    return 0;
}
