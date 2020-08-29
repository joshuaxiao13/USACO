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
	
	ifstream cin ("haybales.in");
	ofstream cout ("haybales.out");
	
	ll n, q;
	cin >> n >> q;
	vl haybales(n);
	for(auto&x : haybales) cin >> x;
	sort(haybales.begin(), haybales.end());
	
	while(q--) {
		ll a, b;
		cin >> a >> b;
		ll hi = ub(haybales.begin(), haybales.end(), b)-haybales.begin()-1;
		ll lo = lb(haybales.begin(), haybales.end(), a)-haybales.begin();
		cout << hi-lo+1 << '\n';
	}
	
	return 0;
}
