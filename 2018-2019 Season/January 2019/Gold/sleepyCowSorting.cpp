#include <bits/stdc++.h>
using namespace std;

struct fenwick_tree {
    vector<int> tree;
    int N;
    fenwick_tree(int n) {
        N = n;
        tree = vector<int>(n+1, 0);
    }
    void add(int k, int x) {
        while (k <= N) {
            tree[k] += x;
            k += k & -k;
        }
    }
    int sum(int k) {
        int ret = 0;
        while (k) {
            ret += tree[k];
            k -= k & -k;
        }
        return ret;
    }
};

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    freopen ("sleepy.in", "r", stdin);
    freopen ("sleepy.out", "w", stdout);
    
    int N; cin >> N;
    
    vector<int> p(N); for (auto& x : p) cin >> x;
    
    fenwick_tree tree(N);
    
    int j = N-1;
    tree.add(p[j], 1);
    
    while (j > 0 && p[j] > p[j-1]) {
        --j;
        tree.add(p[j], 1);
    }
    
    vector<int> ans;
    
    for (int i = 0; i < j; ++i) {
        ans.push_back(j - 1 + tree.sum(p[i]) - i);
        tree.add(p[i], 1);
    }
    
    cout << ans.size() << '\n';

    for (int i = 0; i < j; ++i) {
        cout << ans[i];
        if (i < j-1) cout << ' ';
    }
    
    cout << '\n';

    return 0;
}
