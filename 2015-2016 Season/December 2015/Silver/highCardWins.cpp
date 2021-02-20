// greedily play smallest remaining card greater than Elsie's current card to score a point
// if not possible to win current round, greedily play smallest card in deck
// use DSU (Disjoint Set Union) to efficiently find smallest card remaining higher than Elsie's card
// Ex. if Elsie plays a card with value x, the card Bessie should play is find(
// handle the case where find(x+1) > 2*N, this means that Bessie will lose the current round regardless of what card she plays

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define f first
#define s second

using ll = long long;
using vi = vector<int>;

const int mxN = 1e5;

int N;
int root[mxN + 2];

void init(int N) {
	for(int i = 1; i <= 2*N + 1; ++i) {
		root[i] = i;
	} 
}

int find(int u) {
	if(root[u] == u) return u;
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
	
	ifstream cin ("highcard.in");
	ofstream cout ("highcard.out");
	
	cin >> N;
	
	vi elsie(N);
	for(int&x : elsie)
		cin >> x;
	
	sort(elsie.begin(), elsie.end());
	
	init(N);
	
	for(int i = 0; i < N; ++i)
		unite(elsie[i], elsie[i] + 1);
	
	int ans = 0;
	
	for(int i = 0; i < N; ++i) {
		int a = find(elsie[i]);
		if(a > 2*N) a = find(1);
		else ++ans;
		unite(a, a + 1);
	}
	
	cout << ans << '\n';
	
	return 0;
}
