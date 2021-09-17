#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
ll wordClass[5000][5001], syb[5001], total[5001], dp[5000][17];
int rhymeClass[26];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    freopen ("poetry.in", "r", stdin);
    freopen ("poetry.out", "w", stdout);
    
    int N, M, K; cin >> N >> M >> K;
    
   for (int i = 0; i < N; ++i) {
        int s, c; cin >> s >> c;
        --c;
        ++syb[s];
        ++wordClass[c][s];
    }
    
    total[0] = 1;
    
    for (int t = 1; t <= K; ++t) {
        for (int s = 1; s <= t; ++s) {
            (total[t] += total[t-s] * syb[s] % MOD) %= MOD;
        }
    }
    
    for (int c = 0; c < N; ++c) {
        for (int s = 1; s <= K; ++s) {
            (dp[c][0] += wordClass[c][s] * total[K-s] % MOD) %= MOD;
        }
    }
    
    for (int c = 0; c < N; ++c) {
        for (int mk = 1; mk < 17; ++mk) {
            dp[c][mk] = dp[c][mk-1] * dp[c][mk-1] % MOD;
        }
    }
    
    while (M--) {
        char e; cin >> e;
        ++rhymeClass[e-'A'];
    }
    
    ll ans = 1;
    
    for (int i = 0; i < 26; ++i) {
        if (rhymeClass[i] == 0) continue;
        ll cnt1 = 0;
        for (int c = 0; c < N; ++c) {
            ll cnt2 = 1;
            for (int mk = 0; mk < 17; ++mk) {
                if (rhymeClass[i]&(1<<mk)) {
                    (cnt2 *= dp[c][mk]) %= MOD;
                }
            }
            (cnt1 += cnt2) %= MOD;
        }
        (ans *= cnt1) %= MOD;
    }
    
    cout << ans << '\n';

    return 0;
}
