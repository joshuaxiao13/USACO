#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second

using ll = long long;
using vi = vector<int>;

const int mxN = 1e3;
int root[mxN];

void init(int N) {
	for(int i = 0; i < N; ++i)
		root[i] = i;
}

int find(int u) {
	if(u == root[u]) return root[u];
	return root[u] = find(root[u]);
}

void unite(int u, int v) {
	u = find(u);
	v = find(v);
	root[u] = v;
}

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("cbarn.in");
	ofstream cout ("cbarn.out");
	
	int N;
	cin >> N;
	
	vector<pair<int,int>> flock;
	
	for(int i = 0; i < N; ++i) {
		int c;
		cin >> c;
		if(c == 0) continue;
		flock.pb(mp(c, i));
	}
	
	int ans = INT_MAX;
	
	for(int k = 0; k < N; ++k) {
		init(N);
		int energy = 0;
		for(auto [num,start] : flock) {
			while(num--) {
				int destination = find(start);
				int d = destination - start;
				if(d < 0) d += N;
				energy += d * d;
				int v = (destination + 1) % N;
				unite(destination, v);
			}
		}
		ans = min(ans, energy);
		rotate(flock.begin(), flock.begin() + 1, flock.end());
	}
	
	cout << ans << '\n';
	
	return 0;
}
