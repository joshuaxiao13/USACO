// Silver: modification of the Bronze problem

#include <bits/stdc++.h>
using namespace std;

#define mt make_tuple
using ll = long long;

const ll INF = 1e18;
const int mxN = 1000;

ll ans[mxN];
int n, cow[mxN][2], blame[mxN];
char direction[mxN];
vector<int> dy, dx;
bool visited[mxN];
vector<int> adj[mxN];

void link(int a, int b) {
	adj[a].push_back(b);
}

int dfs(int a) {
	visited[a] = true;
	for(auto b : adj[a]) blame[a] += dfs(b);
	return blame[a] + 1;
}

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> n;
	priority_queue<tuple<int,int,int>> pq;
	
	for(int i = 0; i < n; ++i) {
		ans[i] = INF;
		char d;
		int x, y;
		cin >> d >> x >> y;
		cow[i][0] = x;
		cow[i][1] = y;
		direction[i] = d;
		if(d == 'N') dy.push_back(i);
		else dx.push_back(i);
	}
	
	for(int j = 0; j < int(dy.size()); ++j) {
		for(int i = 0; i < int(dx.size()); ++i) {
			
			int id1, x1, y1, id2, x2, y2;
			id1 = dy[j];
			id2 = dx[i];
			x1 = cow[id1][0];
			y1 = cow[id1][1];
			x2 = cow[id2][0];
			y2 = cow[id2][1];
			
			if((x1 - x2) < 0 || (y2 - y1) < 0 || (x1 - x2) == (y2 - y1)) continue;
			
			if((x1 - x2) > (y2 - y1)) pq.push(mt(-(x1 - x2), id2, id1));
			else pq.push(mt(-(y2 - y1), id1, id2));
		}
	}
	
	while(!pq.empty()) {
		int cnt, id1, id2;
		tie(cnt, id1, id2) = pq.top();
		
		if(ans[id1] == INF) {	
			if(ans[id2] == INF) ans[id1] = -cnt, link(id2, id1);
			else if(direction[id2] == 'N' && cow[id2][1] + ans[id2] >= cow[id1][1]) ans[id1] = -cnt, link(id2, id1);
			else if(direction[id2] == 'E' && cow[id2][0] + ans[id2] >= cow[id1][0]) ans[id1] = -cnt, link(id2, id1);
		}
		
		pq.pop();
	}
	
	for(int i = 0; i < n; ++i)
		if(ans[i] == INF) dfs(i);
	
	for(int i = 0; i < n; ++i)
		cout << blame[i] << '\n';
	
	return 0;
}
