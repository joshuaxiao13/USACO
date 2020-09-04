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
	
	ifstream cin ("cowjog.in");
	ofstream cout ("cowjog.out");
	
	ll N, T;
	cin >> N >> T;
	vl pos(N);
	for(int i=0; i<N; ++i) {
		int s, v;
		cin >> s >> v;
		pos[i] = s + v*T;
	}
	
	int ans = 0;
	
	for(int i=N-1; i>=0; --i) {
		ll curPos = pos[i];
		while(i-1>=0 && pos[i-1]>=curPos) --i;
		++ans;
	}
	
	cout << ans << '\n';
	return 0;
}
