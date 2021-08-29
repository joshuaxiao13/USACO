#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 1e5 + 1;
vector<int> children[mxN];
int filenameLength[mxN], filesInSubTree[mxN];

ll dfs(int u) {
	if (children[u].empty()) {
		filesInSubTree[u] = 1;
		return filenameLength[u];
	}
	ll ret = 0;
	for (auto v : children[u]) {
		ret += dfs(v);
		filesInSubTree[u] += filesInSubTree[v];
	}
	ret += filenameLength[u] * filesInSubTree[u];
	return ret;
}

int main() {	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	freopen("dirtraverse.in", "r", stdin);
	freopen("dirtraverse.out", "w", stdout);

	int N; cin >> N;

	for (int i = 0; i < N; ++i) {
		string name; 
		int m; 
		cin >> name >> m;
		if (m == 0) {
			filenameLength[i] = name.size();
			filesInSubTree[i] = 1;
		} else {
			filenameLength[i] = name.size() + 1;
			children[i].resize(m);
			for (auto& x : children[i]) cin >> x, --x;
		}
	}

	queue<pair<int, ll>> q;

	q.push({0, dfs(0) - filenameLength[0] * filesInSubTree[0]});

	long long ans = 1e18;

	while (!q.empty()) {
		auto [u, cost] = q.front();
		q.pop();
		ans = min(ans, cost);
		for (auto v : children[u]) {
			int inner = filesInSubTree[v];
			int outer = filesInSubTree[0] - inner;
			ll newCost = cost - inner * filenameLength[v] + outer * 3;
			q.push({v, newCost});
		}
	}

	cout << ans << '\n';

	return 0;
}
