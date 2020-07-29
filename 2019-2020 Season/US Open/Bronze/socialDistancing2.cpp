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
	
	ofstream cout ("socdist2.out");
	ifstream cin ("socdist2.in");
 	
 	int n;
 	cin>>n;
 	
 	vpi cow(n);
 	
 	for(int i=0; i<n; ++i) {
		int x,s;
		cin>>x>>s;
		cow[i]={x,s};
	}
	
	sort(cow.begin(), cow.end());
	
	int mxRadius=INT_MAX;
	
	vi sick;
	
	for(int i=0; i<n-1; ++i) {
		if(cow[i].s!=cow[i+1].s) {
			mxRadius=min(cow[i+1].f-cow[i].f, mxRadius);
		}
		if(cow[i].s) sick.pb(cow[i].f);
	}
	
	if(cow.back().s==1) sick.pb(cow.back().f);
	
	--mxRadius;
	
	int ans=0;
	
	for(int i=0; i<sick.size()-1; ++i)
		if(sick[i+1]-sick[i]>mxRadius)
			++ans;
 	
 	cout<<ans+1<<"\n";
	return 0;
}

