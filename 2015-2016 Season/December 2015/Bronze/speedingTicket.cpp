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
	
	ofstream cout ("speeding.out");
	ifstream cin ("speeding.in");
	
	int n,m, sum=0;
	cin>>n>>m;
	
	vector<pi> road(n);
	
	for(int i=0; i<n; ++i) {
		int a,b;
		cin>>a>>b;
		sum+=a;
		road[i]={sum,b};
	}
	
	int ans=0;
	int idx=0;
	int curSum=0;
	
	for(int i=0; i<m; ++i) {
		int a,b;
	 	cin>>a>>b;
	 	curSum+=a;
	 	ans=max(ans, b-road[idx].s);
		
		while(curSum>road[idx].f) {
			++idx;
			ans=max(ans, b-road[idx].s);
		}
		
		if(curSum==road[idx].f) ++idx;
	}
 	
 	cout<<ans<<"\n";
	return 0;
}

