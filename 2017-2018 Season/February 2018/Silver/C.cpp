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
	
	ifstream cin ("teleport.in");
	ofstream cout ("teleport.out");
	
	map<ll,ll> m; 	//m[i] = difference in slope of line formed by (i-1)th and ith breakpoint and slope of line formed by ith and (i+1)th breakpoint
	
	int N;
	cin >> N;
	int haul[N][2];
	
	for(int i=0; i<N; ++i) cin >> haul[i][0] >> haul[i][1];
	
	ll d = 0;
	for(int i=0; i<N; ++i) {
		int a = haul[i][0];
		int b = haul[i][1];
		d += abs(a-b);
		
		if(abs(a)>=abs(a-b)) continue;		//distance from a to 0 is greater than equal to distance between a and b
		else if(a>=0 && a<b) --m[2*a], m[b]+=2, --m[2*(b-a)];
		else if(a>=0 && b<a) --m[2*b], m[b]+=2, --m[0];
		else if(a<0 && b<a)  --m[2*(b-a)], m[b]+=2, --m[2*a];
		else if(a<0 && a<b) --m[0], m[b]+=2, --m[2*b];
	}
	
	ll ans = d, sumOfD = d, curSlope = 0, prevLoc = -1e8;
	
	for(auto x : m) {
		ll loc, deltaM;
		tie(loc, deltaM) = x;
		
		sumOfD += curSlope*(loc - prevLoc);
		curSlope += deltaM;
		prevLoc = loc;
		ans = min(ans, sumOfD);
	}
	
	cout << ans << '\n';
	return 0;
}
