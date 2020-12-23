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

const int mxN = 1e5;
int n;
ll ans = 0;
vi adj[mxN];
bool visited[mxN];

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> n;
	
	for(int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b, --a, --b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	
	queue<int> q;
	q.push(0);
	
	while(!q.empty()) {
		int cnt = 1;
		int a = q.front(); q.pop();
		visited[a] = true;
		
		for(auto b : adj[a]) {
			if(!visited[b]) {
				++cnt;
				q.push(b);
			}
		}
		
		ans += ceil(log(cnt)/log(2));
		ans += cnt - 1;
	}
	
	cout << ans << '\n';
	return 0;
}
