#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("cbarn2.in");
	ofstream cout ("cbarn2.out");
	
	int n, k;
	cin >> n >> k;
	
	vector<ll> R(n);
	for (auto& x : R) cin >> x;
	reverse(R.begin(), R.end());
	
	auto getR = [&](int x, int rotate) {
		return R[(x + rotate) % n];
	};
	
	ll ans = 1e18;
	
	for (int rotate = 0; rotate < n; ++rotate) {
		vector<vector<ll>> cost(n+1, vector<ll>(n+1, 0));
		for (int l = n; l > 0; --l) {
			cost[l][l] = getR(l-1, rotate);
			for (int r = l+1; r <= n; ++r) {
				cost[l][r] = cost[l][r-1] + getR(r-1, rotate);
			}
			for (int r = l+1; r <= n; ++r) {
				cost[l][r] += cost[l][r-1];
			}
		}
		vector<vector<ll>> dp(k + 1, vector<ll>(n + 1, 1e18));
		dp[0][0] = 0;
		for (int i = 1; i <= k; ++i) {
			for (int j = i; j <= n; ++j) {
				for (int l = 0; l < j; ++l) {
					dp[i][j] = min(dp[i][j], dp[i-1][l] + cost[l+1][j-1]);
				}
			}
		}
		ans = min(ans, dp[k][n]);
	}
	
	cout << ans << '\n';
	
	return 0;
}
