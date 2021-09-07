#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    freopen ("cowpatibility.in", "r", stdin);
    freopen ("cowpatibility.out", "w", stdout);
    
    int N; cin >> N;
    
    ll ans = 1LL * N * (N-1) / 2;
    
    map<array<int, 5>, int> M;
    array<int, 5> icecream;

    while (N--) {
        for (auto& x : icecream) cin >> x;
        sort(icecream.begin(), icecream.end());
        for (int k = 1; k < (1 << 5); ++k) {
            array<int, 5> subset = {};
            int id = 0;
            for (int mk = 0; mk < 5; ++mk) {
                if (k & (1 << mk)) subset[id++] = icecream[mk];
            }
            if (__builtin_popcount(k) % 2 == 0) {
                ans += M[subset];
            } else {
                ans -= M[subset];
            }
            ++M[subset];
        }
    }
    
    cout << ans << '\n';

    return 0;
}
