#include <bits/stdc++.h>
using namespace std;

struct fenwick_tree {
    vector<int> tree;
    int n;
    fenwick_tree(int N) { 
        tree = vector<int>(N+1, 0);
        n = N;
    }
    void add(int x, int k) {
        while (k <= n) {
            tree[k] += x;
            k += k & -k;
        }
    }
    int sum(int k) {
        int ret = 0;
        while (k > 0) {
            ret += tree[k];
            k -= k & -k;
        }
        return ret;
    }
};

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    ifstream cin ("circlecross.in");
    ofstream cout ("circlecross.out");

    int N; cin >> N;
    
    vector<int> id(2*N); for (auto& x : id) cin >> x, --x;

    fenwick_tree tree(N);
    vector<int> idx(N, 0);
    
    int i = 1, ans = 0;
    
    for (auto x : id) {
        if (idx[x] > 0) {
            ans += tree.sum(N) - tree.sum(idx[x]);
            tree.add(-1, idx[x]);
        } else {
            idx[x] = i++;
            tree.add(1, idx[x]);
        }
    }
    
    cout << ans << '\n';
    
    return 0;
}
