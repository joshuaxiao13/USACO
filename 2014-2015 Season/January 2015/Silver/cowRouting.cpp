#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define f first
#define s second

using ll = long long;
using vi = vector<int>;

const ll INF = 1e18;
const int mxN = 1000;

pair<ll,int> cost[mxN][mxN];
pair<ll,int> d[mxN];
bool processed[mxN];

void init() {
	for(int i = 0; i < mxN; ++i) {
		d[i] = {INF, mxN};
		for(int j = 0; j < mxN; ++j) {
			if(i == j) cost[i][j] = {0, 0};
			else cost[i][j] = {INF, mxN};
		}
	}
}

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("cowroute.in");
	ofstream cout ("cowroute.out");
	
	init();
	
	int A, B, N;
	cin >> A >> B >> N, --A, --B;
	
  	// first find find shortest distance between every city in a route
  	// shortest distance includes both cost and number of cities visited
  
	for(int i = 0; i < N; ++i) {
		ll w;
		int m;
		cin >> w >> m;
		vi route(m);
		for(int&x : route) cin >> x, --x;
		for(int j = 0; j < m; ++j) {
			for(int k = 0; k < j; ++k) {
				cost[route[k]][route[j]] = min(cost[route[k]][route[j]], make_pair(w, j - k));
			}
		}
	}
	
	priority_queue<tuple<ll,int,int>> pq;
	pq.push(make_tuple(0, 0, A));
	d[A] = {0, 0};
	
	while(!pq.empty()) {
		int u = get<2>(pq.top());
		pq.pop();
		if(u == B) break;
		if(processed[u]) continue;
		processed[u] = true;
		for(int v = 0; v < mxN; ++v) {
			if(cost[u][v].f == INF || u == v) continue;
			pair<ll,int> p = {d[u].f + cost[u][v].f, d[u].s + cost[u][v].s};
			if(d[v] > p) {
				d[v] = p;
				pq.push(make_tuple(-d[v].f, -d[v].s, v));
			}
		}
	}
	
	if(d[B].f == INF) cout << "-1 -1\n";
	else cout << d[B].f << " " << d[B].s << '\n';
	
	return 0;
}
