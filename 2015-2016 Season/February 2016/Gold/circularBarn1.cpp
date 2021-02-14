#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second

using ll = long long;
using vi = vector<int>;

const int mxN = 1e5;
int root[mxN];
int depth[mxN];

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
		flock.pb(mp(c, i));
	}
	
	for(int i = 0; i < N; i = (i + 1) % N) {
		if(flock[i].f == 0) continue;
		int j, cowCnt = flock[i].f - 1;
		for(j = i + 1; ; j = (j + 1) % N) {
			cowCnt += flock[j].f;
			if(cowCnt == 0 || j == i) break;
			--cowCnt;
		}
		if(j == i) {
			rotate(flock.begin(), flock.begin() + i, flock.end());
			break;
		}
		i = j;
	}
	
	ll ans = 0;
	init(N);
	
	for(auto [num,start] : flock) {
		while(num--) {				
			int destination = find(start);
			int d = destination - start;
			if(d < 0) d += N;
			ans += 1LL * d * d;
			int v = (destination + 1) % N;
			unite(destination, v);
		}
	}
	
	cout << ans << '\n';
	
	return 0;
}
