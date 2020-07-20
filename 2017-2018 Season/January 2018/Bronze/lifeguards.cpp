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
	
	ofstream cout ("lifeguards.out");
	ifstream cin ("lifeguards.in");
 	
 	int n;
 	cin>>n;
 	vpi guards(n);
 	
 	for(int i=0; i<n; ++i) {
		int start, end;
		cin>>start>>end;
		guards[i]={start,end};
	}
	
	sort(guards.begin(), guards.end());
	
	int ans=0;
	
	for(int i=0; i<n; ++i) {
		int curTime=0;
		int temp=0;
		for(int j=0; j<n; ++j) {
			if(i==j) continue;
			
			curTime=max(curTime, guards[j].f);
			if(guards[j].s-curTime>0) temp+=guards[j].s-curTime;
			curTime=max(curTime, guards[j].s);
		}
		ans=max(ans,temp);
	}
 	
 	cout<<ans<<"\n";
	return 0;
}
