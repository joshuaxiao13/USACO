#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("feast.in");
	ofstream cout ("feast.out");
	
	int T; cin >> T;
	
	vector<int> fruit(2); for (int& x : fruit) cin >> x;
	
	vector<vector<bool>> dp(T+1, vector<bool>(2, false));
	dp[0][0] = dp[0][1] = true;
	
	int ans = 0;
	
	for (int i = 0; i < 2; ++i) {
		for (int f = 0; f <= T; ++f) {
			if (!dp[f][i]) continue;
			ans = max(ans, f);
			if (i == 0) dp[f/2][1] = true;
			for (int x : fruit) {
				if (f + x <= T) dp[f+x][i] = true;
			}
		}
	}
	
	cout << ans << '\n';

	return 0;
}
