#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> indexed_set;
 
const ll INF = 1e18;
const int MOD = 1e9+7;

bool visited[100001];
int node[100001];
int color[100001];
vi adj1[100001];
set<int> adj2[100001];
int N, M, cnt = 0;

void dfs1(int a) {
	
	if(visited[a]) return;
	visited[a] = true;
	node[a] = cnt;
	
	for(auto b : adj1[a]) dfs1(b);
}

bool dfs2(int a, int col) {
	
	if(visited[a]) {
		return true;
	}
	visited[a] = true;
	color[a] = col;
	
	for(auto b : adj2[a]) {
		if(visited[b] && color[b] == col) {
			return false;
		}
		else dfs2(b, col == 1 ? 0 : 1);
	}
	
	return true;
}
 
int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("revegetate.in");
	ofstream cout ("revegetate.out");
	
	cin >> N >> M;
	
	vpi different;
	
	while(M--) {
		char c;
		int a, b;
		cin >> c >> a >> b;
		if(c == 'S') {
			adj1[a].pb(b);
			adj1[b].pb(a);
		}
		else different.pb({a, b});
	}
	
	for(int i = 1; i <= N; ++i) {
		if(!visited[i]) ++cnt, dfs1(i);
	}
	
	for(auto x : different) {
		int a, b;
		tie(a, b) = x;
		adj2[node[a]].insert(node[b]);
		adj2[node[b]].insert(node[a]);
	}
	
	for(int i = 1; i <= N; ++i) visited[i] = false;
	int numOfComponents = 0;
	
	for(int i = 1; i <= cnt; ++i) {
		if(!visited[i]) {
			if(!dfs2(i, 0)) {
				cout << "0\n";
				return 0;
			}
			else ++numOfComponents;
		}
	}

	cout << '1';
	for(int i = 0 ; i < numOfComponents; ++i) cout << '0';
	cout << '\n';
	return 0;
}


