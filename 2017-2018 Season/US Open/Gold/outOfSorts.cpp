#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    
    int N; cin >> N;
    
    vector<pair<int, int>> A(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i].first;
        A[i].second = i;
    }
    
    vector<int> psum(N, 0);
    
    sort(A.begin(), A.end());
    
    for (int i = 0; i < N; ++i) {
        if (i > A[i].second) {
            ++psum[A[i].second];
            --psum[i];
        }
    }
    
    int ans = psum[0];
    
    for (int i = 1; i < N; ++i) ans = max(ans, psum[i] += psum[i-1]);
    
    cout << max(1, ans) << '\n';
    
    return 0;
}
