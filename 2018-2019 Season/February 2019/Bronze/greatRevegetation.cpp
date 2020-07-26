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
	
	ofstream cout ("revegetate.out");
	ifstream cin ("revegetate.in");
	
	int n,m;
	cin>>n>>m;
	vector<si> pasture(n+1);
	vector<si> notGood(n+1);
	vpi cow(m+1);
	
	for(int i=1; i<=m; ++i) {
		int p1,p2;
		cin>>p1>>p2;
		pasture[p1].insert(i);
		pasture[p2].insert(i);
		cow[i]={p1,p2};
	}
	
	string ans="";
	
	for(int i=1; i<=n; ++i) {
		for(int k=1; k<=4; ++k) {
			if(notGood[i].count(k)==0) {
				ans+=char(k+48);
				
				for(auto x : pasture[i]) {
					notGood[cow[x].f].insert(k);
					notGood[cow[x].s].insert(k);
				}
				break;
			}
		}
	}
	
	cout<<ans<<"\n";
	return 0;
}
