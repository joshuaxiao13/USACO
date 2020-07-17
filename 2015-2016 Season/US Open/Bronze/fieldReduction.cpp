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
	
	ofstream cout ("reduce.out");
	ifstream cin ("reduce.in");
 	
 	int n;
 	cin>>n;
 	si xPos, yPos;
 	map<int,int> xS,yS;
 	set<pi> locations;
 	
 	while(n--) {
		int x,y;
		cin>>x>>y;
		xPos.insert(x);
		yPos.insert(y);
		locations.insert({x,y});
		++xS[x];
		++yS[y];
	}
	
 	int ans=(*--xPos.end()-*xPos.begin())*(*--yPos.end()-*yPos.begin());
 	
 	if(yS[*--yPos.end()]==1) {
		if(locations.count({*--xPos.end(),*--yPos.end()})) ans=min(ans, (*--(--yPos.end())-*yPos.begin())*(*--(--xPos.end())-*xPos.begin()));
		else ans=min(ans, (*--(--yPos.end())-*yPos.begin())*(*--xPos.end()-*xPos.begin()));
	}
 	
 	if(xS[*--xPos.end()]==1) {
		if(locations.count({*--xPos.end(),*yPos.begin()})) ans=min(ans, (*--(--xPos.end())-*xPos.begin())*(*--yPos.end()-*++yPos.begin()));
		else ans=min(ans, (*--(--xPos.end())-*xPos.begin())*(*--yPos.end()-*yPos.begin()));
	}
 	
 	if(yS[*yPos.begin()]==1) {
		if(locations.count({*xPos.begin(),*yPos.begin()})) ans=min(ans, (*--xPos.end()-*++xPos.begin())*(*--yPos.end()-*++yPos.begin()));
		else ans=min(ans, (*--xPos.end()-*++xPos.begin())*(*--yPos.end()-*yPos.begin()));
	}
 	
 	if(xS[*--xPos.begin()]==1) {
		if(locations.count({*xPos.begin(),*--yPos.end()})) ans=min(ans, (*--xPos.end()-*++xPos.begin())*(*--(--yPos.end())-*yPos.begin()));
		else ans=min(ans, (*--xPos.end()-*++xPos.begin())*(*--yPos.end()-*yPos.begin()));
	}
 	
 	cout<<ans<<"\n";
	return 0;
}
