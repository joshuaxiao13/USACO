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
 
const ll INF = 1e18;
const int MOD = 1e9+7;

vector<tuple<int,int,int>> cow;
vi adj[200];
int cnt=0;

void dfs(int a, vector<bool>& visited) {

	if(visited[a]) return;
	visited[a]=true;
	++cnt;
	
	for(auto b: adj[a]) dfs(b, visited);
}
 
int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("moocast.in");
	ofstream cout ("moocast.out");
	
	int n;
	cin >> n;
	cow.resize(n);
	for(int i=0; i<n; ++i) {
		int x, y, r;
		cin >> x >> y >> r;
		cow[i]=(make_tuple(x,y,r));
	}
	
	for(int i=0; i<n; ++i) {
		for(int j=i+1; j<n; ++j) {
			
			int x1, y1, r1, x2, y2, r2;
			tie(x1, y1, r1)=cow[i];
			tie(x2, y2, r2)=cow[j];
			
			int dx=abs(x2-x1), dy=abs(y2-y1);
			int d=dx*dx+dy*dy;
			if(r1*r1>=d) adj[i].pb(j);
			if(r2*r2>=d) adj[j].pb(i);
		}
	}
	
	int ans=1;
	
	for(int i=0; i<n; ++i) {
		cnt=0;
		vector<bool> visited(n, false);
		dfs(i, visited);
		ans=max(ans, cnt);
	}
	
	cout << ans << '\n';
	return 0;
}
