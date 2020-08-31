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
 
const ll INF = 1e18;
const int MOD = 1e9+7;
 
int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("maxcross.in");
	ofstream cout ("maxcross.out");
	
	int n, k, b;
	cin >> n >> k >> b;
	
	vi broken(b);
	for(auto&q : broken) cin >> q;
	
	sort(broken.begin(), broken.end());
	
	int ans=n;
	
	for(int i=1; i<=n && i+k-1<=n; ++i) {
		int lo = lb(broken.begin(), broken.end(), i)-broken.begin();
		int hi = ub(broken.begin(), broken.end(), i+k-1)-broken.begin()-1;
		ans = min(ans, hi-lo+1);	
	}
	
	cout << ans << '\n';
	
	return 0;
}
