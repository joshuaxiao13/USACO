#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    ifstream cin ("bphoto.in");
    ofstream cout ("bphoto.out");
    
    int N; cin >> N;
    
    vector<int> h(N); for (auto& x : h) cin >> x;
    
    vector<int> id(N);
    iota(id.begin(), id.end(), 0);
    sort(id.begin(), id.end(), [&](int a, int b) {
        return h[a] > h[b];
    });
    
    vector<int> tree(N + 1, 0);
    
    auto add = [&](int x, int k) {
        while (k <= N) {
            tree[k] += x;
            k += k & -k;
        }
    };
    
    auto sum = [&](int k) {
        int ret = 0;
        while (k > 0) {
            ret += tree[k];
            k -= k & -k;
        }
        return ret;
    };
    
    int ans = 0;
    
    for (int i = 0; i < N; ++i) {
        int k = id[i] + 1; // 1-indexed
        int L = sum(k-1) - sum(0);
        int R = sum(N) - sum(k);
        if (max(L, R) > 2 * min(L, R)) ++ans;
        add(1, k);
    }
    
    cout << ans << '\n';

    return 0;
}
