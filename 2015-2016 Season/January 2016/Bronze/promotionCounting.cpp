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
	
	ofstream cout ("promote.out");
	ifstream cin ("promote.in");
	
	vector<vi> a(4, vi(2));
	int after=0, before=0;
	
	for(int div=0; div<4; ++div) {
		for(int i=0; i<2; ++i) {
			cin>>a[div][i];
			if(i==0) before+=a[div][0];
			else after+=a[div][1];
		}
	}
	
	a[0][0]+=after-before;
	vi ans(4,0);
	
	for(int i=3; i>=0; i--) {
		if(a[i][0]==a[i][1]) continue;
		
		else {
			int idx=i-1;
			
			while(a[i][0]!=a[i][1]) {
				
				if(a[i][0]+a[idx][0]>=a[i][1]) {
					
					for(int k=idx; k<i; k++) {
						ans[k]+=a[i][1]-a[i][0];
					}
					
					a[idx][0]-=a[i][1]-a[i][0];
					a[i][0]=a[i][1];
				}
				
				else {
					
					for(int k=idx; k<i; k++) {
						ans[k]+=a[idx][0];
					}
					
					a[i][0]+=a[idx][0];
					a[idx][0]=0;
					--idx;
				}
			}
		}
	}
	
	for(int i=0; i<3; i++)
		cout<<ans[i]<<"\n";
	
	return 0;
}
