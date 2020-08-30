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
	
	ifstream cin ("cowcode.in");
	ofstream cout ("cowcode.out");
	
	string s;
	ll n;
	cin >> s >> n;
	
	while(n>s.size()) {
		if((n-1)%s.size()==0 && ((n-1)/s.size())%2==0 && __builtin_popcount((n-1)/s.size()/2)==1) --n;
		else {
			ll temp = ceil(log(double(n)/s.size())/log(2));
			n-=(1LL<<(temp-1))*s.size()+1;
		}
	}
	
	cout << s[n-1] << '\n';
	return 0;
}
