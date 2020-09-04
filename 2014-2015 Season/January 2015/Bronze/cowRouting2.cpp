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
	
	ofstream cout ("cowroute.out");
   	ifstream cin ("cowroute.in");

	int a,b,n;
	cin>>a>>b>>n;
	
	vi cost(n);
	vector<vi> route(n);
	
	vi aToCity(10001, 1e5);
   	vi cityToB(10001, 1e5);
   	aToCity[a]=0;
   	cityToB[b]=0;
	
	for(int i=0; i<n; i++) {
		int p;
		cin>>cost[i]>>p;
		
		for(int j=0; j<p; j++) {
			int x;
			cin>>x;
			route[i].pb(x);
		}
	}
	
	for(int i=0; i<n; i++) {
		
		int aIdx=int(route[i].size()), bIdx=-1;
		
		for(int j=0; j<int(route[i].size()); j++) {
			if(route[i][j]==a) 	aIdx=j;
			else if(route[i][j]==b) bIdx=j;
		}

		for(int j=0; j<int(route[i].size()); j++) {
			if(j>aIdx)  aToCity[route[i][j]]=min(aToCity[route[i][j]], cost[i]);
			if(j<bIdx)  cityToB[route[i][j]]=min(cityToB[route[i][j]], cost[i]);
		}
	}
	
	int ans=1e5;
	
	for(int i=1; i<10000; i++) ans=min(ans, aToCity[i]+cityToB[i]);
	
	if(ans<1e5) cout<<ans<<"\n";
	else cout<<"-1\n";
	
	return 0;
}
