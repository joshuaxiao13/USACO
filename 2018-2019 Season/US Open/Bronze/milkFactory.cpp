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

void possible(vector<si> path, int i, si &start, int n, int initial) {
	
	for(auto x: path[i]) {
		if(start.count(x)==1) continue;
		else if(start.count(x)==0) {
			start.insert(x);
			possible(path,x,start,n,initial);
		}
	}
}
 
int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ofstream cout ("factory.out");
	ifstream cin ("factory.in");
 	
 	int n;
 	cin>>n;
 	vector<si> path(n+1);
 	
 	for(int i=0; i<n-1; ++i) {
		int a,b;
		cin>>a>>b;
		path[b].insert(a);
	}
	
	for(int i=1; i<=n; ++i) {
		si start;
		if(possible(path,i,start,n,i)) {
			cout<<i<<"\n";
			return 0;
		}
	}
 	
 	cout<<"-1\n";
	return 0;
}
