#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int dp[100][101][100];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);
    
    int N; cin >> N;
    
    vector<int> a(N); for (auto& x : a) cin >> x;
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= N; ++j) {
            for (int k = 0; k < N; ++k) {
                dp[i][j][k] = INF;
            }
        }
    }

    dp[0][1][0] = (a[0] != 0);
    
    for (int day = 1; day < N; ++day) {
        for (int b = 1; b <= day + 1; ++b) {
            for (int x = 0; x <= day; ++x) {
                if (x == 0) {
                    for (int i = 0; i < day; ++i) {
                        dp[day][b][x] = min(dp[day][b][x], dp[day-1][b-1][i] + (a[day] != 0));
                    }
                } else {
                    dp[day][b][x] = dp[day-1][b][x-1] + (a[day] != x);
                }
            }
        }
    }
    
    for (int b = 1; b <= N; ++b) {
        int best = N;
        for (int x = 0; x < N; ++x) {
            best = min(best, dp[N-1][b][x]);
        }
        cout << best << '\n';
    }

    return 0;
}
