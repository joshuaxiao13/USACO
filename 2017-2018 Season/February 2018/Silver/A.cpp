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
 
int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("reststops.in");
	ofstream cout ("reststops.out");
	
	ll L;
	ll N, rF, rB;
	cin >> L >> N >> rF >> rB;
	
	vpi grass(N);
	for(int i=0; i<N; ++i) cin >> grass[i].s >> grass[i].f;
	
	sort(grass.rbegin(), grass.rend());
	
	ll ans = 0;
	int idx = 0, prevPos = 0;
	
	while(idx<N) {
		
		int c, x;
		tie(c, x) = grass[idx];
		
		ans += (rF-rB)*(x-prevPos)*c;
		prevPos = x;
		
		++idx;
		while(idx<N && grass[idx].s<prevPos) ++idx;
	}
	
	cout << ans << '\n';
	return 0;
}
