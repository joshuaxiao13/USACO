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

	int a,b,n, ans=INT_MAX;
	cin>>a>>b>>n;

	for(int i=0; i<n; i++) {
		bool aFound=false;
		int p, cost;
		cin>>cost>>p;
		
		while(p--) {
			int x;
			cin>>x;
			
			if(x==a) aFound=true;
			else if(x==b && aFound) ans=min(ans,cost);
		}
	}
	
	if(ans!=INT_MAX) cout<<ans<<"\n";
	else cout<<"-1\n";
	
	return 0;
}
