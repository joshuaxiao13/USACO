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
 
int N, Q, cnt;
vector<pair<int,ll>> adj[5001];

void dfs(int a, vector<bool> &visited, int k) {
	
	if(visited[a]) return;
	visited[a]=true;
	
	for(auto x : adj[a]) {
		int b=x.f, relevance=x.s;
		if(relevance<k) continue;
		else if(!visited[b]) ++cnt, dfs(b, visited, k);
	}
}

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("mootube.in");
	ofstream cout ("mootube.out");
	
	cin >> N >> Q;
	vpi question(Q);
	
	for(int i=0; i<N-1; ++i) {
		int a, b;
		ll c;
		cin >> a >> b >> c;
		adj[a].pb({b,c});
		adj[b].pb({a,c});
	}
	
	for(int i=0; i<Q; ++i)  {
		ll k, v;
		cin >> k >> v;
		cnt=0;
		vector<bool> visited(N+1, false);
		dfs(v, visited, k);
		cout << cnt << '\n';
	}
	
	return 0;
}
