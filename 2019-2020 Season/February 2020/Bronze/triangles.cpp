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
	
	ofstream cout ("triangles.out");
	ifstream cin ("triangles.in");
 	
 	int n;
 	cin>>n;
 	vpi point(n);
 	set<pi> s;
 	for(int i=0; i<n; ++i) {
		int x,y;
		cin>>x>>y;
		point[i]={x,y};
		s.insert({x,y});
	}
	
	ll ans=0;
	
	for(int j=0; j<n; ++j) {
		for(int i=j+1; i<n; ++i) {
			int x1,y1,x2,y2;
			tie(x1,y1)=point[j];
			tie(x2,y2)=point[i];
			if(s.count({x1,y2})==1 || s.count({x2,y1})) {
				ans=max(ans, ll(abs(x1-x2))*abs(y2-y1));
			}
		}
	}
 	
 	cout<<ans<<"\n";
	return 0;
}
