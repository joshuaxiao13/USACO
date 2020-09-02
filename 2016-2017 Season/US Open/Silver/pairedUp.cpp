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
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> indexed_set;

const ll INF = 1e18;
const int MOD = 1e9+7;
 
int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("pairup.in");
	ofstream cout ("pairup.out");
	
	int n;
	cin >> n;
	vpi cows(n);
	
	int ans=0;
	
	for(int i=0; i<n; ++i) cin >> cows[i].s >> cows[i].f;
	
	sort(cows.begin(), cows.end());
	
	int lo=0, hi=n-1;
	
	while(lo<=hi) {
		
		ans=max(ans, cows[lo].f+cows[hi].f);
		
		if(cows[lo].s<cows[hi].s) cows[hi].s-=cows[lo].s, ++lo;
		else if(cows[lo].s>cows[hi].s) cows[lo].s-=cows[hi].s, --hi;
		else ++lo, --hi;
	}
	
	cout << ans << '\n';
	return 0;
}
