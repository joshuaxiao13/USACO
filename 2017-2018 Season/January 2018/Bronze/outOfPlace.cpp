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
	
	ofstream cout ("outofplace.out");
	ifstream cin ("outofplace.in");
 	
 	int n, idx=-1;
 	ll ans=0;
 	cin>>n;
 	vi lineup(n);
 	
 	for(int&q: lineup) cin>>q;
	
	bool swapLeft=false;
	
	if(lineup[0]>lineup[1]) {
		idx=0;
	}
	
	else if(lineup[n-1]<lineup[n-2]) {
		idx=n-1;
		swapLeft=true;
	}
	
	else{
		
		for(int i=1; i<n-1; ++i) {
			if(lineup[i]>lineup[i-1] && lineup[i]>lineup[i+1] && lineup[i+1]>=lineup[i-1]) {
				idx=i;
				break;
			}
			else if(lineup[i]<lineup[i-1] && lineup[i]<lineup[i+1] && lineup[i+1]>=lineup[i-1]) {
				swapLeft=true;
				idx=i;
				break;
			}
		}
	}
	
	if(idx==-1) {
		cout<<"0\n";
		return 0;
	}
	
	else {
		
		int original=idx;
		
		if(swapLeft) {

			while(idx-1>=0 && lineup[original]<lineup[idx-1]) {
				--idx;
				
				while(idx-1>=0 && lineup[idx]==lineup[idx-1]) --idx;
				
				++ans;
			}
		}
		
		else {
			
			while(idx+1<n && lineup[original]>lineup[idx+1]) {
				++idx;
				
				while(idx+1<n && lineup[idx]==lineup[idx+1]) ++idx;
				
				++ans;
			}
		}
	}
	
	cout<<ans<<"\n";
	return 0;
}
