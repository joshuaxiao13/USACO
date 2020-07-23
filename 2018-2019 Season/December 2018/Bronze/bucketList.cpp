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
	
	ofstream cout ("blist.out");
	ifstream cin ("blist.in");
 	
 	int n, initialT=INT_MAX, finalT=INT_MIN;
 	cin>>n;
 	
 	vi start(1001,-1), end(1001,-1);
 	
 	for(int i=0; i<n; ++i) {
		int s,t,b;
		cin>>s>>t>>b;
		
		start[s]=b;
		end[t]=b;
		
		initialT=min(s, initialT);
		finalT=max(t, finalT);
	}
	
	int ans=0, temp=0;
	
	for(int i=initialT; i<=finalT; ++i) {
		if(start[i]!=-1) temp+=start[i];
		else if(end[i]!=-1) temp-=end[i];
		
		ans=max(ans, temp);
	}
	
	cout<<ans<<"\n";
	return 0;
}
