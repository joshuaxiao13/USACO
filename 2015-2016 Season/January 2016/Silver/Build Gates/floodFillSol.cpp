// idea is to "enlarge the grid" so that lattice points can also be represented
// not just cells on the grid/farm, flood fill from any point and count the number
// of faces in the planar graph

#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define eb emplace_back
#define f  first
#define s  second

using ll = long long;
using vi = vector<int>;

const int mxN = 4000;

bool fence[mxN + 1][mxN + 1];

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

bool valid(int y, int x) {
	return y >= 0 && y <= mxN && x >= 0 && x <= mxN && !fence[y][x];
}

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	ifstream cin ("gates.in");
	ofstream cout ("gates.out");

	int N;
	string s;
	
	cin >> N >> s;
	
	int curY = 2000, curX = 2000;
	fence[curY][curX] = true;
	
	for(int i = 0; i < N; ++i) {
		int k;
		if(s[i] == 'N') k = 0;
		else if(s[i] == 'E') k = 1;
		else if(s[i] == 'S') k = 2;
		else k = 3;
		for(int r = 0; r < 2; ++r) {
			curY += dy[k];
			curX += dx[k];
			fence[curY][curX] = true;
		}
	}

	int faces = 0;
	for(int j = 0; j <= mxN; ++j) {
		for(int i = 0; i <= mxN; ++i) {
			if(fence[j][i]) continue;
			++faces;
			queue<pair<int,int>> q;
			q.push({j, i});
			while(!q.empty()) {
				int y, x;
				tie(y, x) = q.front(); q.pop();
				if(fence[y][x]) continue;
				fence[y][x] = true;
				for(int k = 0; k < 4; ++k) {
					int yy = y + dy[k];
					int xx = x + dx[k];
					if(valid(yy, xx)) {
						q.push({yy, xx});
					}
				}
			}
		}
	}

	cout << faces - 1 << '\n';

	return 0;
}
