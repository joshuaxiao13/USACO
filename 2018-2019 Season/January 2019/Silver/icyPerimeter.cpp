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

int N, ans1 = 0, ans2 = 0;
bool g[1000][1000];
bool visited[1000][1000];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool inBounds(int r, int c) {
	
	return r >= 0 && r < N && c >= 0 && c < N;
}

int getPerimeter(int r, int c) {
	
	int perimeter = 0;
	for(int k = 0; k < 4; ++k) {
		if(inBounds(r + dy[k], c + dx[k]) && !g[r+dy[k]][c+dx[k]]) ++perimeter;
	}
	
	if(r == 0) ++perimeter;
	if(r == N - 1) ++perimeter;
	if(c == 0) ++perimeter;
	if(c == N - 1) ++perimeter;
	
	return perimeter;
}

void bfs(int j, int i, int &area, int &perimeter) {
	
	visited[j][i] = true;
	queue<pi> q;
	q.push({j, i});
	
	while(!q.empty()) {
		
		int r, c;
		tie(r, c) = q.front(); q.pop();
		++area;
		perimeter += getPerimeter(r, c);
		
		for(int k = 0; k < 4; ++k) {
			if(inBounds(r + dy[k], c + dx[k]) && g[r+dy[k]][c+dx[k]] && !visited[r+dy[k]][c+dx[k]]) {
				visited[r+dy[k]][c+dx[k]] = true;
				q.push({r+dy[k], c+dx[k]});
			}
		}
	}
}

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("perimeter.in");
	ofstream cout ("perimeter.out");
	
	cin >> N;
	
	for(int j = 0; j < N; ++j) {
		string row;
		cin >> row;
		for(int i = 0; i < N; ++i) {
			g[j][i] = row[i] == '#' ? 1 : 0;
		}
	}
	
	for(int j = 0; j < N; ++j) {
		for(int i = 0; i < N; ++i) {
			if(visited[j][i] || !g[j][i]) continue;
			int area = 0, perimeter = 0;
			bfs(j, i, area, perimeter);
			if(area > ans1) ans1 = area, ans2 = perimeter;
			else if(area == ans1) ans2 = min(ans2, perimeter);
		}
	}
	
	cout << ans1 << " " << ans2 << '\n';
	return 0;
}

