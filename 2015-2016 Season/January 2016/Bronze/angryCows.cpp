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
	
	ofstream cout ("angry.out");
	ifstream cin ("angry.in");
	
	int n;
	cin>>n;
	vi hb(n);
	
	for(int&j : hb) cin>>j;
	sort(hb.begin(), hb.end());
	
	int ans=1;
	
	for(int i=0; i<n; i++) {
		
		int t=0;
		int right=i;
		int left=i;
		
		int tempLeft=left;
		int tempRight=right;
		
		bool keepGoingRight=true, keepGoingLeft=true;
		bool keepGoing=true;
		
		while(keepGoing) {
	
			keepGoing=false;
			int radius=t+1;
			
			while(keepGoingLeft && left>0 && hb[left-1]>=hb[tempLeft]-radius) --left;
			while(keepGoingRight && right<n-1 && hb[right+1]<=hb[tempRight]+radius) ++right;
			
			
			if(tempLeft>left) {
				keepGoing=true;
				keepGoingLeft=true;
				tempLeft=left;
			}
			
			else keepGoingLeft=false;
			
			if(tempRight<right) {
				keepGoing=true;
				keepGoingRight=true;
				tempRight=right;
			}
			
			else keepGoingRight=false;
			
			++t;
		}
		
		ans=max(ans, right-left+1);
	}
 	
 	cout<<ans<<"\n";
	return 0;
}
