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
	
	ofstream cout ("gymnastics.out");
	ifstream cin ("gymnastics.in");
	
	int k,n;
	cin>>k>>n;
	vector<vi> p(k, vi(n));
	
	for(int j=0; j<k; ++j) {
		for(int i=0; i<n; ++i) {
			int q;
			cin>>q;
			p[j][q-1]=i;
		}
	}
	
	int ans=0;
	
	for(int j=0; j<n; ++j) {
		for(int i=j+1; i<n; ++i) {
			
			bool good=true;
			
			for(int a=1; a<k && good; ++a)	
				if((p[0][j]<p[0][i])!=(p[a][j]<p[a][i])) good=false;
	
			if(good) ++ans;
		}
	}
 	
 	cout<<ans<<"\n";
	return 0;
}
