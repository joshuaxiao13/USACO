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
	
	ofstream cout ("square.out");
	ifstream cin ("square.in");
	
	int x1=10, x2=1, y1=10, y2=1;
	
	for(int i=0; i<2; ++i) {
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		x1=min(x1,a);
		y1=min(y1,b);
		x2=max(x2,c);
		y2=max(y2,d);
	}
	
	int ans=max(x2-x1,y2-y1);
	cout<<ans*ans<<"\n";
	return 0;
}
