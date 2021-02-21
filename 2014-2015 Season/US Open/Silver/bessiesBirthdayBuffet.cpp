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
	
	
	// BFS from every node to find shortest path
	
	queue<int> q;
	
	for(int i = 0; i < N; ++i) {
		vector<bool> vis(N, false);
		dis[i][i] = 0;
		vis[i] = true;
		q.push(i);
		while(!q.empty()) {
			int u = q.front(); q.pop();
			for(auto v : adj[u]) {
				if(!vis[v] && dis[i][v] > dis[i][u] + 1) {
					dis[i][v] = dis[i][u] + 1;
					q.push(v);
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
