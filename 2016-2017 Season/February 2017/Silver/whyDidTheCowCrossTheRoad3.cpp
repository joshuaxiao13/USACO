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

vi dx={1,0,-1,0};
vi dy={0,1,0,-1};
vpi adj[100][100];
int n;

void dfs(pi a, vector<vector<bool>> &visited) {
	
	int r,c;
	tie(r,c)=a;
	
	if(visited[r][c]) return;
	visited[r][c]=true;
	
	for(int i=0; i<4; ++i) {
		if(r+dx[i]<0 || r+dx[i]>=n || c+dy[i]<0 || c+dy[i]>=n) continue;
		bool road=false;
		for(auto x: adj[r][c]) {
			if(x.f==dx[i] && x.s==dy[i]) {
				road=true;
				break;
			}
		}
		if(!road) dfs({r+dx[i], c+dy[i]}, visited);
	}
}
 
int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("countcross.in");
	ofstream cout ("countcross.out");
	
	int k, r;
	cin >> n >> k >> r;
	vpi cow(k);
	
	while(r--) {
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		--r1, --c1, --r2, --c2;
		adj[r1][c1].pb({r2-r1, c2-c1});
		adj[r2][c2].pb({r1-r2, c1-c2});
	}
	
	for(int i=0; i<k; ++i) {
		int r, c;
		cin >> r >> c;
		--r, --c;
		cow[i].f=r;
		cow[i].s=c;
	}
	
	int ans=0;
	
	for(int i=0; i<k; ++i) {
		vector<vector<bool>> visited(n, vector<bool>(n, false));
		dfs(cow[i], visited);
		for(int j=i+1; j<k; ++j) {
			if(!visited[cow[j].f][cow[j].s]) ++ans;
		}
	}
	
	cout << ans << '\n';
	return 0;
}
