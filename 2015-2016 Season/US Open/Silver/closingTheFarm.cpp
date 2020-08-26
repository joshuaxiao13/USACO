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
typedef unsigned long ul;
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef set<int> si;
typedef multiset<int> mi;
 
const ll INF = 1e18;
const int MOD = 1e9+7;

vi adj[3001];

void dfs(int a, vector<bool> &visited) {
	
	if(visited[a]) return;
	visited[a]=true;
	
	for(auto b : adj[a])
		dfs(b, visited);
}
 
int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("closing.in");
	ofstream cout ("closing.out");
	
	int n, m;
	cin >> n >> m;
	
	while(m--) {
		int a ,b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	
	vi order={0};
	for(int i=0; i<n; ++i) {
		int a;
		cin >> a;
		order.pb(a);
	}
	
	set<int> s;
	
	for(int i=0; i<n; ++i) {
		
		s.insert(order[i]);
		vector<bool> visited(n+1, false);
		adj[order[i]].clear();
		bool good=true;
		
		dfs(order.back(), visited);
		
		for(int i=1; i<=n && good; ++i) {
			if(s.count(i)) continue;
			else if(!visited[i]) good=false;
		}
		
		if(good) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}
