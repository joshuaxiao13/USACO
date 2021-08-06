#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e6;
int root[MAXN];
int depth[MAXN];

void init(int n) {
	for (int i = 0; i < n; ++i) {
		root[i] = i;
	}
}

int find(int u) {
	if (root[u] == u) return u;
	return root[u] = find(root[u]);
}

bool same(int u, int v) {
	return find(u) == find(v);
}

void unite(int u, int v) {
	u = find(u);
	v = find(v);
	if (depth[u] > depth[v]) swap(u, v);
	root[u] = v;
	depth[v] = max(depth[v], depth[u] + 1);
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("fencedin.in");
	ofstream cout ("fencedin.out");
	
	int A, B, n, m;
	
	cin >> A >> B >> n >> m;
	
	vector<int64_t> a(n); for (auto& x : a) cin >> x;
	vector<int64_t> b(m); for (auto& y : b) cin >> y;
	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	
	vector<pair<int64_t, int> > horizontal, vertical;
	
	for (int i = 0; i <= n; ++i) {
		int64_t length = (i == n ? A : a[i]) - (i > 0 ? a[i-1] : 0);
		horizontal.emplace_back(length, i);
	}
	
	for (int j = 0; j <= m; ++j) {
		int64_t length = (j == m ? B : b[j]) - (j > 0 ? b[j-1] : 0);
		vertical.emplace_back(length, j);
	}
	
	sort(horizontal.begin(), horizontal.end());
	sort(vertical.begin(), vertical.end());
	
	vector<tuple<int64_t, int, int> > edges;
	
	int idxH = 0, idxV = 0;
	int H = horizontal.size(), V = vertical.size();
	
	while (idxH < H || idxV < V) {
		if (idxH < H && ((idxV < V && horizontal[idxH].first < vertical[idxV].first) || idxV >= V)) {
			int64_t length;
			int col;
			tie(length, col) = horizontal[idxH];
			for (int j = 0; j < m; ++j) {
				int id1 = j*(n+1) + col;
				int id2 = (j+1)*(n+1) + col;
				edges.emplace_back(length, id1, id2);
			}
			++idxH;
		} else {
			int64_t length;
			int row;
			tie(length, row) = vertical[idxV];
			for (int i = 0; i < n; ++i) {
				int id1 = row*(n+1) + i;
				int id2 = row*(n+1) + i + 1;
				edges.emplace_back(length, id1, id2);
			}
			++idxV;
		}
	}
	
	int64_t ans = 0;
	int regions = (n+1) * (m+1);
	
	init(regions);
	
	--regions;
	
	for (int i = 0; regions > 0; ++i) {
		int64_t length;
		int id1, id2;
		tie(length, id1, id2) = edges[i];
		if (!same(id1, id2)) {
			unite(id1, id2);
			ans += length;
			--regions;
		}
	}
	
	cout << ans << '\n';
	
	return 0;
}
