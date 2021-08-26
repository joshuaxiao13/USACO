#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    ifstream cin ("cownomics.in");
    ofstream cout ("cownomics.out");
    
    int N, M; cin >> N >> M;

    vector<vector<string> > gene(2, vector<string>(N));

    for (auto& x : gene) for (auto& cow : x) cin >> cow;

    vector<vector<int> > diff(N, vector<int>(N, 0));

    int cnt = 0, ans = M, r = 0;

    for (int l = 0; l < M; ++l) {
        while (cnt < N*N && r < M) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    if (gene[0][i][r] != gene[1][j][r]) {
                        if (++diff[i][j] == 1) ++cnt;
                    }
                }
            }
            ++r;
        }
        if (cnt == N*N) ans = min(ans, r - l);
        else break;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (gene[0][i][l] != gene[1][j][l]) {
                    if (--diff[i][j] == 0) --cnt;
                }
            }
        }
    }

    cout << ans << '\n';
    
    return 0;
}
