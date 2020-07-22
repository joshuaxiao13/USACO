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
	
	ofstream cout ("milkorder.out");
	ifstream cin ("milkorder.in");
 	
 	int n,m,k;
 	cin>>n>>m>>k;
 	
 	vi position(n+1,-1);
 	vi order(n+1,-1);
 	vi socialH(m);
 	for(int&q : socialH) cin>>q;
 	
 	for(int i=0; i<k; ++i) {
		int cow, pos;
		cin>>cow>>pos;
		order[pos]=cow;
		position[cow]=pos;
	}
	
	if(position[1]!=-1) {
		cout<<position[1]<<"\n";
		return 0;
	}
	
	int idx=n;
	for(int i=m-1; i>=0; --i) {
		
		if(position[socialH[i]]!=-1) idx=position[socialH[i]];
			
		else if(socialH[i]==1) {
			
			int idx=1;
			
			for(int j=0; j<=i; ++j) {
				
				if(position[socialH[j]]!=-1) idx=position[socialH[j]];
				
				else {
					while(order[idx]!=-1) ++idx;
					order[idx]=socialH[j];
					position[socialH[j]]=idx;
				}
			}
			break;
		}
			
		else {
			while(order[idx]!=-1) --idx;
			order[idx]=socialH[i];
			position[socialH[i]]=idx;
		}
	}
	
	if(position[1]!=-1) cout<<position[1]<<"\n";
	
	else {
		for(int i=1; i<=n; ++i) {
			if(order[i]==-1) {
				cout<<i<<"\n";
				break;
			}
		}
	}
	
	return 0;
}
