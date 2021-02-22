#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define f first
#define s second

using ll = long long;
using vi = vector<int>;

const int mxN = 1e5;
int N, K;
unordered_set<int> landOn[mxN];
int succ[mxN], ans[mxN];
bool vis[mxN], passport[mxN];

int dfs(int u) {
	vis[u] = true;
	for(auto x : landOn[u])
		passport[x] = true;
	if(!vis[succ[u]])
		return ans[u] = dfs(succ[u]);
	for(int i = 0; i < N; ++i)
		if(passport[i]) 
			++ans[u];
	return ans[u];
}

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> N >> K;
	
	vi pos(N);
	
	for(int i = 0; i < N; ++i) {
		pos[i] = i;
		landOn[i].insert(i);
	}
		
	while(K--) {
		int a, b;
		cin >> a >> b, --a, --b;
		landOn[pos[a]].insert(b);
		landOn[pos[b]].insert(a);
		swap(pos[a], pos[b]);
	}
	
	for(int i = 0; i < N; ++i)
		succ[pos[i]] = i;
		
	for(int u = 0; u < N; ++u) {
		if(!vis[u]) {
			for(int i = 0; i < N; ++i)
				passport[i] = false;
			dfs(u);
		}
	}

	for(int i = 0; i < N; ++i)
		cout << ans[i] << '\n';
	
	return 0;
}
