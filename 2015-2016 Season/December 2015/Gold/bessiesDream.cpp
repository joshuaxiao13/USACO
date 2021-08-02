#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const pair<int,int> dxy[] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("dream.in");
	ofstream cout ("dream.out");
	
	int N, M; cin >> N >> M;
	
	vector<vector<int>> g(N, vector<int>(M));
	
	for (auto& r : g) for (auto& c : r) cin >> c;
	
	int best[N][M][2];
	bool processed[N][M][2];
	
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			best[i][j][0] = best[i][j][1] = INF;
			processed[i][j][0] = processed[i][j][1] = false;
		}
	}
	
	priority_queue<tuple<int, pair<int,int>, bool>> pq;
	
	best[0][0][0] = 0;
	pq.push(make_tuple(0, make_pair(0, 0), false));
	
	auto inBound = [&](int r, int c) {
		return min(r, c) >= 0 && r < N && c < M;
	};
	
	while (!pq.empty()) {
		int r, c;
		bool orange;
		tie(r, c) = get<1>(pq.top());
		orange = get<2>(pq.top());
		pq.pop();
		if (processed[r][c][orange]) continue;
		processed[r][c][orange] = true;
		for (auto [dx, dy] : dxy) {
			int R = r + dy;
			int C = c + dx;
			if (inBound(R, C)) {
				if (g[R][C] == 1 && !processed[R][C][orange] && best[R][C][orange] > best[r][c][orange] + 1) {
					best[R][C][orange] = best[r][c][orange] + 1;
					pq.push(make_tuple(-best[R][C][orange], make_pair(R, C), orange));
				} else if (g[R][C] == 2 && !processed[R][C][1] && best[R][C][1] > best[r][c][orange] + 1) {
					best[R][C][1] = best[r][c][orange] + 1;
					pq.push(make_tuple(-best[R][C][1], make_pair(R, C), true));
				} else if (g[R][C] == 3 && orange && !processed[R][C][1] && best[R][C][1] > best[r][c][orange] + 1) {
					best[R][C][1] = best[r][c][1] + 1;
					pq.push(make_tuple(-best[R][C][1], make_pair(R, C), true));
				} else if (g[R][C] == 4) {
					int steps = 1;
					while (g[R][C] == 4 && inBound(R + dy, C + dx) && g[R+dy][C+dx] != 0 && g[R+dy][C+dx] != 3) R += dy, C += dx, ++steps;
					bool curOrange = (g[R][C] == 2);
					if (!processed[R][C][curOrange] && best[R][C][curOrange] > best[r][c][orange] + steps) {
						best[R][C][curOrange] = best[r][c][orange] + steps;
						pq.push(make_tuple(-best[R][C][curOrange], make_pair(R, C), curOrange));
					}
				}
			}
		}
	}
	
	int ans = min(best[N-1][M-1][0], best[N-1][M-1][1]);
	
	cout << (ans == INF ? -1 : ans) << '\n';
	
	return 0;
}
