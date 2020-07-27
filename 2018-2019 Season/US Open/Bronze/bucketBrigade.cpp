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

int ans=INT_MAX;
vector<vi> dp(10, vi(10,200));

void solve(vector<vector<char>> v) {
	
	for(int k=0; k<19; ++k) {
		for(int j=0; j<10; ++j) {
			for(int i=0; i<10; ++i) {
				if(v[i][j]=='R') continue;
				if(i-1>=0 && v[j][i-1]!='R') dp[j][i]=min(dp[j][i],dp[j][i-1]+1);
				if(i+1<10 && v[j][i+1]!='R') dp[j][i]=min(dp[j][i],dp[j][i+1]+1);
				if(j-1>=0 && v[j-1][i]!='R') dp[j][i]=min(dp[j][i],dp[j-1][i]+1);
				if(j+1<10 && v[j+1][i]!='R') dp[j][i]=min(dp[j][i],dp[j+1][i]+1);
				
				if(v[j][i]=='L') ans=min(ans, dp[j][i]);
			}
			
		}
	}
}
 
int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ofstream cout ("buckets.out");
	ifstream cin ("buckets.in");
 	
 	vector<vector<char>> v(10, vector<char>(10));
 	pi lake, barn;
 	
 	for(int j=0; j<10; ++j) {
		for(int i=0; i<10; ++i) {
			cin>>v[j][i];
			if(v[j][i]=='B') dp[j][i]=-1;
		}
	}
	
	solve(v);
	cout<<ans<<"\n";
	return 0;
}
