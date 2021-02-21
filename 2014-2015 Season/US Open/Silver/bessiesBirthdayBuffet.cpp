#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define f first
#define s second

using ll = long long;
using vi = vector<int>;

const int INF = 1e6;

int N, E;
int dis[1000][1000];
int energy[1000];
int dp[1000];
vi adj[1000];

bool cmp(int u, int v) {
	return energy[u] > energy[v];
}

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("buffet.in");
	ofstream cout ("buffet.out");
	
	cin >> N >> E;
	
	for(int j = 0; j < N; ++j) {
		for(int i = 0; i < N; ++i) {
			dis[j][i] = INF;
		}
	}
	
	for(int u = 0; u < N; ++u) {
		int D;
		cin >> energy[u] >> D;
		while(D--) {
			int v;
			cin >> v, --v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
	}
	
	// Dijkstra's on every node
	
	priority_queue<pair<int,int>> pq;
	
	for(int i = 0; i < N; ++i) {
		vector<bool> processed(N, false);
		dis[i][i] = 0;
		pq.push({0, i});
		while(!pq.empty()) {
			int u = pq.top().s; pq.pop();
			if(processed[u]) continue;
			processed[u] = true;
			for(auto v : adj[u]) {
				if(dis[i][v] > dis[i][u] + 1) {
					dis[i][v] = dis[i][u] + 1;
					pq.push({-dis[i][v], v});
				}
			}
		}
	}
	
	// sort nodes in decreasing order of energy gained
	
	vi order(N);
	iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(), cmp);
	
	int ans = 0;
	
	for(int i = 0; i < N; ++i) {
		dp[order[i]] = energy[order[i]];
		for(int j = 0; j < i; ++j) {
			if(dis[order[i]][order[j]] == INF) continue;
			dp[order[i]] = max(dp[order[i]], energy[order[i]] + dp[order[j]] - E*dis[order[i]][order[j]]); 
		}
		ans = max(ans, dp[order[i]]);
	}
	
	cout << ans << '\n';
	
	return 0;
}
