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

int N, M, cnt = 0;
bool inPlace[100001];
bool visited[100001];
vpi adj[100001];

int dfs(int a, int x) {
	
	if(visited[a]) {
		return 0;
	}
	visited[a] = true;
	int ret = 0;
	if(!inPlace[a]) ret = 1;
	
	for(auto p : adj[a]) {
		int b, w;
		tie(b, w) = p;
		if(w >= x) ret += dfs(b, x);
	}
	
	return ret;
}

bool valid(int x) {
	
	bool good = false;
	for(int i = 1; i <= N; ++i) {
		if(!inPlace[i] && dfs(i, x) == N - cnt) {
			good = true;
			break;
		}
	}
	
	for(int i = 1; i <= N; ++i) visited[i] = false;
	return good;
}
 
int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("wormsort.in");
	ofstream cout ("wormsort.out");
	
	cin >> N >> M;
	
	for(int i = 1; i <= N; ++i)  {
		int a;
		cin >> a;
		inPlace[i] = (a == i);
		if(a == i) ++cnt;
	}
	
	int mx = 0;
	
	for(int i = 0; i < M; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		adj[a].pb({b, w});
		adj[b].pb({a, w});
		mx = max(mx, w);
	}
	
	int ans = 1;
	if(cnt == N) ans = -1;
	else {
		for(int k = mx/2; k >= 1; k/=2)
			while(ans + k <= mx && valid(ans + k)) ans += k;
	}
	
	cout << ans << '\n';
	return 0;
}
