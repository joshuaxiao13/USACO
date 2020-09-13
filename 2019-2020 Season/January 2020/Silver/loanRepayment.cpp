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

ll N, K, M;

bool valid(ll x) {
	
	ll G = 0, days = 0;
	
	while(G < N) {
		
		ll y = (N - G)/x;
		
		if(y <= M) {
			days += (N - G + M - 1)/M;
			break;
		}
		else {
			ll gallonsUntilNewY = N - G - x * y + 1;
			ll daysUntilNewY = (gallonsUntilNewY + y - 1)/y;
			days += daysUntilNewY;
			G += daysUntilNewY * y;
		}
	}
	
	return days <= K;
}

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("loan.in");
	ofstream cout ("loan.out");
	
	cin >> N >> K >> M;
	
	ll ans = 1;
	
	for(ll k = N/2; k >= 1; k/=2)
		while(ans + k < N && valid(ans + k)) ans += k; 
		
	cout << ans << '\n';
	
	return 0;
}

