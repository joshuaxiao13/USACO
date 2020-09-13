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

int N, M, mnW, cnt;
int pos[100001];
int inComponent[100001];
bool visited[100001];
vpi adj[100001];
set<int> s;

void dfs(int a) {
	
	if(visited[a]) return;
	visited[a] = true;
	inComponent[a] = cnt;
	
	for(auto p : adj[a]) {
		int b, w;
		tie(b, w) = p;
		if(w >= mnW) dfs(b);
	}
}

bool valid(int k) {

	bool good = true;
	auto it = s.begin();
	advance(it, k);
	mnW = *it;
	cnt = 0;
	
	for(int i = 1; i <= N; ++i) if(!visited[i]) ++cnt, dfs(i);
	
	for(int i = 1; i <= N; ++i) {
		if(inComponent[i] != inComponent[pos[i]]) {
			good = false;
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
	
	bool sorted = true;
	for(int i = 1; i <= N; ++i)  {
		int a;
		cin >> a;
		pos[i] = a;
		if(i != a) sorted = false;
	}
	
	for(int i = 0; i < M; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		adj[a].pb({b, w});
		adj[b].pb({a, w});
		s.insert(w);
	}
	
	int ans = 0;
	if(sorted) ans = -1;
	else {
		for(int k = s.size()/2; k >= 1; k/=2) {
			while(ans + k < s.size() && valid(ans + k)) ans += k;
		}
		
		auto it = s.begin();
		advance(it, ans);
		ans = *it;
	}
	
	cout << ans << '\n';
	return 0;
}

