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
	
	ofstream cout ("pails.out");
	ifstream cin ("pails.in");
 	
 	int x,y,m;
 	cin>>x>>y>>m;
 	
 	vi dp(m+1,0);
 	dp[x]=x;
 	
 	for(int i=x+1; i<=m; ++i) {
		dp[i]=dp[i-1];
		if(i-x>=x) dp[i]=max(dp[i-x]+x, dp[i]);
		if(i-y>=x) dp[i]=max(dp[i-y]+y, dp[i]);
	}
	
	cout<<dp[m]<<"\n";
	return 0;
}

