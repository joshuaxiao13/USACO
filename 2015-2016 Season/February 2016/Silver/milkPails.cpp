#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define f first
#define s second

using ll = long long;
using vi = vector<int>;

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("pails.in");
	ofstream cout ("pails.out");
	
	int X, Y, K, M;
	cin >> X >> Y >> K >> M;
	
	vector<vector<int>> dp(X + 1, vector<int>(Y + 1, K + 1));       // dp[a][b] = minimum number of operations to get 'a' and 'b' units of milk in first and second pails respectively
	dp[0][0] = 0;
	
	for(int i = 1; i <= K; ++i) {
		for(int a = 0; a <= X; ++a) {
			for(int b = 0; b <= Y; ++b) {
				if(dp[a][b] == i - 1) {
					// empty first bucket
					dp[0][b] = min(dp[0][b], i);
					// empty second bucket
					dp[a][0] = min(dp[a][0], i);
					// fill first bucket
					dp[X][b] = min(dp[X][b], i);
					// fill second bucket
					dp[a][Y] = min(dp[a][Y], i);
					// pour first into second
					if(b + a <= Y)
						dp[0][b+a] = min(dp[0][b+a], i);
					else
						dp[a+b-Y][Y] = min(dp[a+b-Y][Y], i);
					// pour second into first
					if(a + b <= X)
						dp[a+b][0] = min(dp[a+b][0], i);
					else
						dp[X][a+b-X] = min(dp[X][a+b-X], i);
				}
			}
		}
	}
	
	int ans = INT_MAX;
	
	for(int a = 0; a <= X; ++a) {
		for(int b = 0; b <= Y; ++b) {
			if(dp[a][b] <= K)
				ans = min(ans, abs(a + b - M));
		}
	}
	
	cout << ans << '\n';
	
	return 0;
}
