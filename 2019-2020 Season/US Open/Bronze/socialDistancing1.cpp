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

bool valid(int n, vi cow, int d) {
	
	int cnt=0;
	
	if(cow[0]/d>=1) cnt+=cow[0]/d;
	if((n-cow.back())/d>=1) cnt+=(n-cow.back())/d;
	
	for(int i=0; i<int(cow.size()-1); ++i) {
		if(cow[i+1]-cow[i]<d) return false;
		else if((cow[i+1]-cow[i])/d>=2) cnt+=(cow[i+1]-cow[i])/d-1;
	}
	
	return cnt>=2;
}
 
int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ofstream cout ("socdist1.out");
	ifstream cin ("socdist1.in");
 	
 	int n;
 	string stall;
 	cin>>n>>stall;
 	vi cow;
 	
 	if(count(stall.begin(),stall.end(),'1')==0) {
		cout<<n-1<<"\n";
		return 0;
	}
 	
 	for(int i=0; i<n; ++i)	
		if(stall[i]=='1') cow.pb(i);
	
	int ans=0;
	
	for(int k=n/2; k>=1; k/=2)
		while(ans+k<n && valid(n,cow,ans+k)) 
			ans+=k;
 	
 	cout<<ans<<"\n";
	return 0;
}

