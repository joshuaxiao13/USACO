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
char farm[100001];
vi adj[100001];
bool visited[100001];
int partOf[100001];

void dfs(int a) {
	
	if(visited[a]) return;
	visited[a] = true;
	partOf[a] = cnt;
	
	for(auto b : adj[a]) if(farm[a] == farm[b]) dfs(b);
}

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("milkvisits.in");
	ofstream cout ("milkvisits.out");
	
	cin >> N >> M;
	string s;
	cin >> s;
	
	for(int i = 0; i < N; ++i) farm[i+1] = s[i];
	
	for(int i = 0; i < N - 1; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	
	for(int i = 1; i <= N; ++i) {
		if(!visited[i]) ++cnt, dfs(i);
	}
	
	string ans = "";
	
	while(M--) {
		int a, b;
		char p;
		cin >> a >> b >> p;
		
		if(farm[a] != farm[b] || partOf[a] != partOf[b]) ans += '1';
		else if(partOf[a] == partOf[b] && farm[a] != p) ans += '0';
		else ans += '1';
	}
	
	cout << ans << '\n';
	return 0;
}

