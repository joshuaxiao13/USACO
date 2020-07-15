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

vpi c;

int solve(int a, int b) {
	
	int quad1=0, quad2=0, quad3=0, quad4=0;
	
	for(auto x: c) {
		if(x.f<a) {
			if(x.s<b) ++quad3;
			else ++quad2;
		}
		
		else {
			if(x.s<b) ++quad4;
			else ++quad1;
		}
	}
			
	return max(max(quad1,quad2), max(quad3,quad4));
}


int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ofstream cout ("balancing.out");
	ifstream cin ("balancing.in");
 	
 	int N,B;
 	cin>>N>>B;
 	unordered_set<int> xCoords, yCoords;
 	
 	c.resize(N);
 	for(int i=0; i<N; ++i) {
		int x,y;
		cin>>x>>y;
		c[i]={x,y};
		xCoords.insert(x-1);
		yCoords.insert(y-1);
	}
	
	int ans=N;
	
	for(auto x : xCoords)
		for(auto y : yCoords)
			ans=min(ans, solve(x,y));

 	cout<<ans<<"\n";
	return 0;
}
