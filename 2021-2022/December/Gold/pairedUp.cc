#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T, N, K; cin >> T >> N >> K;

	vector<pair<int, int>> cow(N+1);
	for (int i = 1; i <= N; ++i) {
		cin >> cow[i].first >> cow[i].second;
	}

	vector<int> sum(N+1, 0);
	for (int i = 1; i <= N; ++i) sum[i] = sum[i-1] + cow[i].second;

	// 0 -> don't pair
	// 1 -> pair adjacent
	// 2 -> pair 2 away
	vector<vector<int>> dp(N+1, vector<int>(3, T == 2 ? INT_MIN : 1e9));

	dp[0][1] = 0;

	int ptr = 0; // keep track of index of rightmost cow greater than K units left of current cow
	int ptr2 = 0; // keep track of index of rightmost cow greater K units to left of the cow to the left of current

	if (T == 1) {
		for (int i = 1; i <= N; ++i) {
			while (ptr + 1 < i && cow[ptr+1].first + K < cow[i].first) { ++ptr; }
			if ((i - ptr - 1) % 2 == 0) {
				dp[i][0] = cow[i].second + min({dp[ptr][0], dp[ptr][1], dp[ptr][2]});
			} else {
				dp[i][0] = cow[i].second + min(dp[ptr+1][1], dp[ptr+1][2]);
			}
			if (i > 1 && cow[i-1].first + K >= cow[i].first) {
				dp[i][1] = min({dp[i-2][0], dp[i-2][1], dp[i-2][2]});
			}
			if (i > 2 && cow[i-2].first + K >= cow[i].first) {
				while (ptr2 + 1 < i-2 && cow[ptr2+1].first + K < cow[i-1].first) { ++ptr2; }
				if ((i-1 - ptr2 - 1 - 1) % 2 == 0) {
					dp[i][2] = cow[i-1].second + min({dp[ptr2][0], dp[ptr2][1], dp[ptr2][2]});
				} else {
					dp[i][2] = cow[i-1].second + min(dp[ptr2+1][1], dp[ptr2+1][2]);
				}
			}
		}
		cout << min({dp[N][0], dp[N][1], dp[N][2]}) << '\n';
	} else {
		for (int i = 1; i <= N; ++i) {
			while (ptr + 1 < i && cow[ptr+1].first + K < cow[i].first) { ++ptr; }
			if ((i - ptr - 1) % 2 == 0) {
				dp[i][0] = cow[i].second + max({dp[ptr][0], dp[ptr][1], dp[ptr][2]});
			} else {
				dp[i][0] = cow[i].second + max(dp[ptr+1][1], dp[ptr+1][2]);
			}
			if (i > 1 && cow[i-1].first + K >= cow[i].first) {
				dp[i][1] = max({dp[i-2][0], dp[i-2][1], dp[i-2][2]});
			}
			if (i > 2 && cow[i-2].first + K >= cow[i].first) {
				while (ptr2 + 1 < i-2 && cow[ptr2+1].first + K < cow[i-1].first) { ++ptr2; }
				if ((i-1 - ptr2 - 1 - 1) % 2 == 0) {
					dp[i][2] = cow[i-1].second + max({dp[ptr2][0], dp[ptr2][1], dp[ptr2][2]});
				} else {
					dp[i][2] = cow[i-1].second + max(dp[ptr2+1][1], dp[ptr2+1][2]);
				}
			}
		}
		cout << max({dp[N][0], dp[N][1], dp[N][2]}) << '\n';
	}

}
