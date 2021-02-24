#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define f first
#define s second

using ll = long long;
using vi = vector<int>;

const int MOD = 1000000007;

int grid[100][100];
int dp[100][100];

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("hopscotch.in");
	ofstream cout ("hopscotch.out");
	
	int n, m, k;
	cin >> n >> m >> k;
	
	for(int j = 0; j < n; ++j) {
		for(int i = 0; i < m; ++i) {
			cin >> grid[j][i];
		}
	}
	
	dp[0][0] = 1;
	
	for(int j = 0; j < n; ++j) {
		for(int i = 0; i < m; ++i) {
			for(int r = j + 1; r < n; ++r) {
				for(int c = i + 1; c < m; ++c) {
					if(grid[j][i] != grid[r][c]) {
						(dp[r][c] += dp[j][i]) %= MOD;
					}
				}
			}
		}
	}
	
	cout << dp[n-1][m-1] << '\n';
	
	return 0;
}
