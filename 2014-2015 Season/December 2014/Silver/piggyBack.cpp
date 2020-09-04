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

int N, M;
vi adj[40001];

vl getBessie() {
	
	vl d(N+1, INF);
	vector<bool> visited(N+1, false);
	d[1]=0;
	
	priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> q;
	q.push({0,1});
	
	while(!q.empty()) {
		int a = q.top().s;
		q.pop();
		if(visited[a]) continue;
		visited[a]=true;
		
		for(auto b : adj[a]) {
			if(d[b]>d[a]+1) {
				d[b]=d[a]+1;
				q.push({d[b], b});
			}
		}
	}
	
	return d;
}

vl getElsie() {
	
	vl d(N+1, INF);
	vector<bool> visited(N+1, false);
	d[2]=0;
	
	priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> q;
	q.push({0,2});
	
	while(!q.empty()) {
		int a = q.top().s;
		q.pop();
		if(visited[a]) continue;
		visited[a]=true;
		
		for(auto b : adj[a]) {
			if(d[b]>d[a]+1) {
				d[b]=d[a]+1;
				q.push({d[b], b});
			}
		}
	}
	
	return d;
}

vl getFarm() {
	
	vl d(N+1, INF);
	vector<bool> visited(N+1, false);
	d[N]=0;
	
	priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> q;
	q.push({0,N});
	
	while(!q.empty()) {
		int a = q.top().s;
		q.pop();
		if(visited[a]) continue;
		visited[a]=true;
		
		for(auto b : adj[a]) {
			if(d[b]>d[a]+1) {
				d[b]=d[a]+1;
				q.push({d[b], b});
			}
		}
	}
	
	return d;
}
 
int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("piggyback.in");
	ofstream cout ("piggyback.out");
	
	int B, E, P;
	cin >> B >> E >> P >> N >> M;
	
	while(M--) {
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	
	vl farm = getFarm();
	vl bessie = getBessie();
	vl elsie = getElsie();
	
	ll ans = INF;
	
	for(int i=1; i<=N; ++i) {
		ll energy = B*bessie[i] + E*elsie[i] + P*farm[i];
		ans = min(ans, energy);
	}
	
	cout << ans << '\n';
	return 0;
}
