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
	
	ofstream cout ("swap.out");
	ifstream cin ("swap.in");
 	
 	int n,k;
 	cin>>n>>k;
 	vi v(n+1);
 	vi sorted(n+1);
 	
 	for(int i=0; i<=n; ++i) v[i]=i;
 	sorted=v;
 	
 	int a1,a2,b1,b2,cycle=-1;
 	cin>>a1>>a2>>b1>>b2;
 	
 	
 	for(int i=0; i<k; ++i) {
		
		reverse(v.begin()+a1,v.begin()+a2+1);
		if(v==sorted) {
			cycle=2*i+1;
			break;
		}
		
		reverse(v.begin()+b1,v.begin()+b2+1);
		if(v==sorted) {
			cycle=2*i+2;
			break;
		}
	}
	
	if(cycle==-1) {
		for(int i=1; i<=n; ++i) cout<<v[i]<<"\n";
	}
	
	else {
		for(int i=0; i<k%cycle; ++i) {
			reverse(sorted.begin()+a1,sorted.begin()+a2+1);
			reverse(sorted.begin()+b1,sorted.begin()+b2+1);
		}
		
		for(int i=1; i<=n; ++i) cout<<sorted[i]<<"\n";
	}
 	
	return 0;
}
