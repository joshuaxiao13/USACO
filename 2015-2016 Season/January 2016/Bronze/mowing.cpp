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
	
	ofstream cout ("mowing.out");
	ifstream cin ("mowing.in");
 	
	int N;
	cin>>N;
	map<pi,int> m;
	int x=0, y=0, t=0, ans=INT_MAX;
	
	while(N--) {
		char D;
		int S;
		cin>>D>>S;
		
		if(D=='N') {
			for(int i=0; i<S; i++) {
				++t;
				++y;
				if(m[{x,y}]!=0) ans=min(t-m[{x,y}], ans);
				m[{x,y}]=t;
			}
		}
		
		else if(D=='S') {
			for(int i=0; i<S; i++) {
				++t;
				--y;
				if(m[{x,y}]!=0) ans=min(t-m[{x,y}], ans);
				m[{x,y}]=t;
			}
		}
		
		else if(D=='E') {
			for(int i=0; i<S; i++) {
				++t;
				++x;
				if(m[{x,y}]!=0) ans=min(t-m[{x,y}], ans);
				m[{x,y}]=t;
			}
		}
		
		else {
			for(int i=0; i<S; i++) {
				++t;
				--x;
				if(m[{x,y}]!=0) ans=min(t-m[{x,y}], ans);
				m[{x,y}]=t;
			}
		}
	}
 	
 	if(ans==INT_MAX) cout<<"-1\n";
 	else cout<<ans<<"\n";
 	
	return 0;
}
