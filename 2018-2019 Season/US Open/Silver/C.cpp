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

struct point {
	int x, y;
};

int N, M, mnX, mxX, mnY, mxY;
vi adj[100001];
bool visited[100001];
point cow[100001];

void dfs(int a) {
	
	if(visited[a]) return;
	visited[a] = true;
	mnX = min(mnX, cow[a].x);
	mxX = max(mxX, cow[a].x);
	mnY = min(mnY, cow[a].y);
	mxY = max(mxY, cow[a].y);
	
	for(auto b : adj[a]) dfs(b);
}
 
int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("fenceplan.in");
	ofstream cout ("fenceplan.out");
	
	cin >> N >> M;
	
	for(int i = 1 ; i <= N; ++i) cin >> cow[i].x >> cow[i].y;
	
	while(M--) {
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	
	int ans = INT_MAX;
	
	for(int i = 1; i <= N; ++i) {
		if(!visited[i]) {
			mnX = INT_MAX, mxX = INT_MIN, mnY = INT_MAX, mxY = INT_MIN;
			dfs(i);
			ans = min(ans, 2*(mxX - mnX) + 2*(mxY - mnY));
		}
	}
	
	cout << ans << '\n';
	return 0;
}
