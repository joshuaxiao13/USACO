#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pi = pair<int, int>;
using vpi = vector<pi>;
using indexed_set = tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>;

const ll INF = 1e18;
const int MOD = 1e9+7;

const int mxN = 2500;
int n, t[mxN], inc[mxN], col[mxN];
vi adj[mxN];

void dfs(int a) {

	col[a] = 1;
	for(auto b : adj[a]) {
		if(col[b] == 0) dfs(b);
	}
	
	for(auto b: adj[a]) {
		if(col[b] != 2) continue;
		int temp = (12 - (t[b] + inc[b]) % 12) % 12;
		inc[b] += temp;
		inc[a] += temp;
		inc[a] %= 12;
	}
	
	col[a] = 2;
}

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("clocktree.in");
	ofstream cout ("clocktree.out");
	
	cin >> n;
	
	for(int i = 0; i < n; ++i) cin >> t[i];
	for(int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	
	int ans = 0;
	
	for(int i = 0; i < n; ++i) {
		for(int i = 0; i < n; ++i) inc[i] = col[i] = 0;
		dfs(i);
		int temp = (t[i] + inc[i]) % 12;
		if(temp == 0 || temp == 1) ++ans;
	}
	
	cout << ans << '\n';
	return 0;
}
