#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define f first
#define s second

using ll = long long;
using vi = vector<int>;

int N;
int root[2000], depth[2000], ID[2000];

int find(int u) {
	if(root[u] == u) return u;
	return root[u] = find(root[u]);
}

bool same(int u, int v) {
	return find(u) == find(v);
}

void unite(int u, int v) {
	u = find(u);
	v = find(v);
	if(depth[u] < depth[v]) swap(u, v);
	root[v] = u;
	depth[u] = max(depth[u], depth[v] + 1);
}

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("superbull.in");
	ofstream cout ("superbull.out");
	
	cin >> N;
	
	for(int i = 0; i < N; ++i) {
		cin >> ID[i];
		root[i] = i;
	}
	
	vector<tuple<int,int,int>> edges;
	
	for(int i = 0; i < N; ++i) {
		for(int j = i + 1; j < N; ++j) {
			edges.eb(ID[i] ^ ID[j], i, j);
		}
	}
	
	ll ans = 0;
	sort(edges.rbegin(), edges.rend());

	// order which the games are played don't matter that much since we end up with a tree and we can always "peel away" the furthest nodes from the root (the winner)

	for(auto [w, u, v] : edges) {
		if(!same(u, v)) {
			unite(u, v);
			--N;
			ans += w;
		}
		if(N == 1)
			break;
	}
	
	cout << ans << '\n';
	
	return 0;
}
