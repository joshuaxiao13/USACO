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
typedef unsigned long ul;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef set<int> si;
typedef multiset<int> mi;
 
const ll INF = 1e18;
const int MOD = 1e9+7;
 
int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ofstream cout ("cow.out");
	ifstream cin ("cow.in");
 	
 	int n;
 	cin>>n;
 	
 	vi O;
 	int C[n];
 	int W[n];
 	int countC=0, countW=0;
 	
 	for(int i=0; i<n; i++) {
		char letter;
		cin>>letter;
		if(letter=='O') O.pb(i);
		else if(letter=='C') ++countC;
		else ++countW;
		
		W[i]=countW;
		C[i]=countC;
	}
	
	ll ans=0;
	
	for(auto x: O)
		ans+=C[x]*(W[n-1]-W[x]);
	
	cout<<ans<<"\n";
	return 0;
}
