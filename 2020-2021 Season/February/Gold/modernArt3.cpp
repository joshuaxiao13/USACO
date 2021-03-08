#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define eb emplace_back
#define f  first
#define s  second

using ll = long long;
using vi = vector<int>;

int dp[300][300], board[300];

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	for(int i = 0; i < N; ++i)
		cin >> board[i];

	for(int j = 0; j < N; ++j) {
		for(int i = 0; i < N; ++i) {
			dp[j][i] = 305;
		}
	}

	for(int L = N - 1; L >= 0; --L) {
		dp[L][L] = 1;
		for(int R = L + 1; R < N; ++R) {
			for(int K = L; K < R; ++K) {
				int deduction = 0;
				deduction += (board[K] == board[K+1]);
				deduction += (board[L] == board[R]);
				deduction -= (board[K] == board[K+1] && board[L] == board[R] && board[K] == board[L]);
				dp[L][R] = min(dp[L][R], dp[L][K] + dp[K+1][R] - deduction);
			}

		}
	}

	cout << dp[0][N-1] << '\n';

	return 0;
}	
