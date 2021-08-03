#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("radio.in");
	ofstream cout ("radio.out");
	
	int N, M, fx, fy, bx, by;
	string john, bessie;
	
	cin >> N >> M >> fx >> fy >> bx >> by >> john >> bessie;
	
	vector<pair<int,int>> johnPos(N+1), bessiePos(M+1);
	johnPos[0] = {fx, fy};
	bessiePos[0] = {bx, by};
	
	for (int i = 1; i <= N; ++i) {
		johnPos[i] = johnPos[i-1];
		if (john[i-1] == 'N') ++johnPos[i].second;
		else if (john[i-1] == 'S') --johnPos[i].second;
		else if (john[i-1] == 'E') ++johnPos[i].first;
		else --johnPos[i].first;
	}
	
	for (int i = 1; i <= M; ++i) {
		bessiePos[i] = bessiePos[i-1];
		if (bessie[i-1] == 'N') ++bessiePos[i].second;
		else if (bessie[i-1] == 'S') --bessiePos[i].second;
		else if (bessie[i-1] == 'E') ++bessiePos[i].first;
		else --bessiePos[i].first;
	}
	
	auto squareDist = [&](int a, int b) {
		return (int) pow(johnPos[a].first - bessiePos[b].first, 2) + (int) pow(johnPos[a].second - bessiePos[b].second, 2);
	};
	
	vector<vector<int>> dp(N+1, vector<int>(M+1, INF));
	
	dp[0][0] = 0;
	
	for (int i = 0; i <= N; ++i) {
		for (int j = 0; j <= M; ++j) {
			if (i+1 <= N) dp[i+1][j] = min(dp[i+1][j], dp[i][j] + squareDist(i+1, j));
			if (j+1 <= M) dp[i][j+1] = min(dp[i][j+1], dp[i][j] + squareDist(i, j+1));
			if (i+1 <= N && j+1 <= M) dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + squareDist(i+1, j+1));
		}
	}
	
	cout << dp[N][M] << '\n';
	
	return 0;
}
