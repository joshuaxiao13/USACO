#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> indexed_set;
 
const ll INF = 1e18;
const int MOD = 1e9+7;

int N, K;
int g[100][100];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool inBounds(int j, int i, int deltaY, int deltaX) {
	
	return j + deltaY >= 0 && j + deltaY < N && i + deltaX >= 0 && i + deltaX < 10;
}

void eliminate(int r, int c) {
	
	int color = g[r][c];
	g[r][c] = 0;
	queue<pi> q;
	q.push({r, c});
	
	while(!q.empty()) {
		int j, i;
		tie(j, i) = q.front(); q.pop();
		
		for(int k = 0; k < 4; ++k) {
			if(inBounds(j, i, dy[k], dx[k]) && g[j+dy[k]][i+dx[k]] == color) {
				g[j+dy[k]][i+dx[k]] = 0;
				q.push({j+dy[k], i+dx[k]});
			}
		}
	}
}

bool bfs(int r, int c, vector<vector<bool>> &visited) {
	
	int cnt = 0;
	queue<pi> q;
	visited[r][c] = true;
	q.push({r, c});
	
	while(!q.empty()) {
		++cnt;
		if(cnt >= K) break;
		int j, i;
		tie(j, i) = q.front(); q.pop();
		
		for(int k = 0; k < 4; ++k) {
			if(inBounds(j, i, dy[k], dx[k]) && g[j+dy[k]][i+dx[k]] == g[r][c] && !visited[j+dy[k]][i+dx[k]]) {
				visited[j+dy[k]][i+dx[k]] = true;
				q.push({j+dy[k], i+dx[k]});
			}
		}
	}
	
	return cnt >= K;
}

void getNewGrid() {
	
	for(int i = 0; i < 10; ++i) {
		int idx = N - 1;
		for(int j = N - 1; j >= 0; --j) {	
			if(g[j][i] != 0) {
				if(idx > j) {
					g[idx][i] = g[j][i];
					g[j][i] = 0;
				}
				--idx;
			}
		}
	}
}
 
int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("mooyomooyo.in");
	ofstream cout ("mooyomooyo.out");
	
	cin >> N >> K;
	
	for(int j = 0; j < N; ++j) {
		string row;
		cin >> row;
		for(int i = 0; i < 10; ++i) {
			g[j][i] = row[i] - '0';
		}
	}
	
	bool keepChecking = true;
	
	while(keepChecking) {
		
		keepChecking = false;
		vector<vector<bool>> visited(N, vector<bool>(10, false));
		
		for(int j = 0; j < N; ++j) {
			for(int i = 0; i < 10; ++i) {
				if(g[j][i] != 0 && !visited[j][i] && bfs(j, i, visited)) {
					keepChecking = true;
					eliminate(j, i);
				}
			}
		}
		
		if(keepChecking) getNewGrid();
	}
	
	for(int j = 0; j < N; ++j) {
		for(int i = 0; i < 10; ++i) {
			cout << g[j][i];
		}
		cout << '\n';
	}
	
	return 0;
}

