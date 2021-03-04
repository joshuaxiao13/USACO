#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define f first
#define s second

using ll = long long;
using vi = vector<int>;

int dy[] = {0, 0, -1, 1};
int dx[] = {-1, 1, 0, 0};

int grid[2001][2001];
int cnt[2001][20001];

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N, ans = 0;
	cin >> N;
	
	// (0, 0) -> maps to -> (500, 500)
	
	while(N--) {
		int x, y;
		cin >> x >> y;
		x += 500;
		y += 500;
		if(grid[x][y] == 1) {
			--ans;
			cout << ans << '\n';
			continue;
		}
		
		grid[x][y] = 1;
		queue<pair<int,int>> q;
		
		for(int k = 0; k < 4; ++k) {
			int X = x + dx[k];
			int Y = y + dy[k];
			if(grid[X][Y] == 1) {
				++cnt[x][y];
				++cnt[X][Y];
				if(cnt[X][Y] == 3) {
					q.push({X, Y});
				}
			}
		}
		
		if(cnt[x][y] == 3) q.push({x, y});

		while(!q.empty()) {
			int i, j;
			tie(i, j) = q.front();
			q.pop();
			if(cnt[i][j] != 3) continue;
			++ans;
			for(int k = 0; k < 4; ++k) {
				int X = i + dx[k];
				int Y = j + dy[k];
				if(grid[X][Y] == 0) {
					grid[X][Y] = 1;
					for(int m = 0; m < 4; ++m) {
						int a = X + dx[m];
						int b = Y + dy[m];
						if(grid[a][b] == 1) {
							++cnt[X][Y];
							++cnt[a][b];
							if(cnt[a][b] == 3) {
								q.push({a, b});
							}
						}
					}
					if(cnt[X][Y] == 3) q.push({X, Y});
					break;
				}
			}
		}
		cout << ans << '\n';
	}
	
	return 0;
}
