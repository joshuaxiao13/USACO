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

int N, regions = 0, ans1 = 1, ans2 = 1;
int g[250][250];							//g[j][i] = ID of j-i th element
int reg[250][250];							//reg[j][i] = region that j-i th element belongs to
int cellsInRegion[62501];						//cellsInRegion[x] = total number of cells/elements in xth region
int id[62501];								//id[x] = ID of cells/elements in xth region
set<int> adj[62501];							//adj[x] stores the adjacent regions of region x
set<int> tested[62501];							//tested[x] stores region x's adjacent IDs that have been tested

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool inBounds(int y, int x, int deltaY, int deltaX) {
	
	return y+deltaY>=0 && y+deltaY<N && x+deltaX>=0 && x+deltaX<N;
}

void bfs(int row, int col) {
	
	++regions;
	int cnt = 0, ID = g[row][col];
	queue<pi> q;
	q.push({row,col});
	
	while(!q.empty()) {
		int r, c;
		tie(r,c) = q.front();
		q.pop();
		++cnt, reg[r][c] = regions;
		
		for(int i=0; i<4; ++i) {
			if(inBounds(r, c, dy[i], dx[i]) && g[r+dy[i]][c+dx[i]]==ID && reg[r+dy[i]][c+dx[i]]==0) {
				reg[r+dy[i]][c+dx[i]] = regions;
				q.push({r+dy[i],c+dx[i]});
			}
		}
	}
	
	ans1 = max(ans1, cnt);
	cellsInRegion[regions] = cnt;
	id[regions] = ID;
}

int dfs(int regionNum, int desiredId, vector<bool> &visited) {
	
	if(visited[regionNum]) return 0;
	tested[regionNum].insert(desiredId);
	visited[regionNum] = true;
	int temp = cellsInRegion[regionNum];
	
	for(auto connected : adj[regionNum]) {
		if(id[connected]==desiredId) temp += dfs(connected, id[regionNum], visited);
	}
	
	return temp;
}
 
int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("multimoo.in");
	ofstream cout ("multimoo.out");
	
	cin >> N;
	
	for(int j=0; j<N; ++j) {
		for(int i=0; i<N; ++i) {
			cin >> g[j][i];
		}
	}
	
	//bfs to find the regions that each element belongs to
	for(int j=0; j<N; ++j) {
		for(int i=0; i<N; ++i) {
			if(reg[j][i]==0) bfs(j, i);
		}
	}
	
	//transverse grid, find connected regions and store in adj[]
	for(int j=0; j<N; ++j) {
		for(int i=0; i<N; ++i) {
			int regionNum = reg[j][i];
			for(int k=0; k<4; ++k) {
				if(inBounds(j, i, dy[k], dx[k]) && reg[j+dy[k]][i+dx[k]]!=regionNum) adj[regionNum].insert(reg[j+dy[k]][i+dx[k]]);
			}
		}
	}
	
	//transverse regions and calculate total number of cells covered by 2 IDs using dfs, optimize using tested[] to calculate each group of regions once only
	for(int k=1; k<=regions; ++k) {
		
		ans2 = max(ans2, cellsInRegion[k]);	//not necessary, problem gurantees two distinct IDs
		set<int> s;
		
		for(auto x : adj[k]) {
			if(tested[k].count(id[x])) continue;
			tested[k].insert(id[x]);
			
			vector<bool> visited(regions+1, false);
			visited[k] = true;
			int total = cellsInRegion[k];
			
			for(auto connected : adj[k]) {
				if(id[connected]==id[x]) total += dfs(connected, id[k], visited);
			}
			
			ans2 = max(ans2, total);
		}
	}
	
	cout << ans1 << '\n' << ans2 << '\n';
	return 0;
}

