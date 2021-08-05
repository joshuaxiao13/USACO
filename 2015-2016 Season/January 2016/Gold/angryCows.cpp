#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("angry.in");
	ofstream cout ("angry.out");
	
	int N; cin >> N;
	
	int x[N]; for (int& y : x) cin >> y;
	
	sort(x, x + N);
	
	vector<vector<double>> dp(2, vector<double>(N));
	
	dp[0][0] = 0;
	int l = 0, r = N-1;
	
	for (int i = 1; i < N; ++i) {
		while (l + 1 < i && x[i] - x[l] > dp[0][l] + 1) ++l;
		dp[0][i] = max(dp[0][l] + 1, double(x[i] - x[l]));
	}
	
	dp[1][N-1] = 0;
	
	for (int i = N-2; i >= 0; --i) {
		while (r - 1 > i && x[r] - x[i] > dp[1][r] + 1) --r;
		dp[1][i] = max(dp[1][r] + 1, double(x[r] - x[i]));
	}
	
	l = 0, r = N-1;
	double ans = DBL_MAX;
	
	while (l < r) {
		ans = min(ans, max(max(dp[0][l], dp[1][r]) + 1, double(x[r] - x[l])/2));
		dp[0][l+1] < dp[1][r-1] ? ++l : --r;
	}
	
	cout << setprecision(1) << fixed << ans << '\n';
	
	return 0;
}
