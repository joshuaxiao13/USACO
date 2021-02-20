#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define f first
#define s second

using ll = long long;
using vi = vector<int>;

int N, M;
bool on[100][100];
bool vis[100][100];
vector<pair<int,int>> turnsOn[100][100];

int dy[] = {0, 0, -1, 1};
int dx[] = {-1, 1, 0, 0};

bool valid(int y, int x) {
	return y >= 0 && y < N && x >= 0 && x < N;
} 

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	//ifstream cin ("lightson.in");
	//ofstream cout ("lightson.out");
	
	cin >> N >> M;
	
	for(int i = 0; i < M; ++i) {
		int x, y, a, b;
		cin >> x >> y >> a >> b, --x, --y, --a, --b;
		turnsOn[y][x].eb(b, a);
	}
	
	int ans = 1;
	on[0][0] = true;
	vis[0][0] = true;
	
	for(auto [y,x] : turnsOn[0][0]) {
		if(!on[y][x]) {
			++ans;
			on[y][x] = true;
		}
	}
	
  // something similar to Bellman Ford, runs N*N - 1 (number of "nodes" - 1) times
  // idea is to start at (1, 1) and see what lights can be turned on, and keep track of
  // which squares are "travel-able" from (1, 1) with 2D array vis, flip on all the switches
  // of squares that are "travel-able", every time a new light is flipped on, increase answer
  
	for(int t = 0; t < N*N - 1; ++t) {
		for(int j = 0; j < N; ++j) {
			for(int i = 0; i < N; ++i) {
				if(vis[j][i] || !on[j][i]) continue;
				for(int k = 0; k < 4 && !vis[j][i]; ++k) {
					int prevY = j + dy[k];
					int prevX = i + dx[k];
					if(valid(prevY, prevX) && vis[prevY][prevX] && on[prevY][prevX]) {
						vis[j][i] = true;
						for(auto [y,x] : turnsOn[j][i]) {
							if(!on[y][x]) {
								++ans;
								on[y][x] = true;
							}
						}
					}
				}
			}
		}
	}
	
	cout << ans << '\n';
	
	return 0;
}
