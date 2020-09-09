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

int N, ans = 1;
int adj[100001];
 
int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("planting.in");
	ofstream cout ("planting.out");

	cin >> N;
	
	for(int i = 0; i < N - 1; ++i) {
		int a, b;
		cin >> a >> b;
		++adj[a];
		++adj[b];
		ans = max({ans, adj[a] + 1, adj[b] + 1});
	}
	
	cout << ans << '\n';
	return 0;
}
