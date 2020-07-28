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
	
	ofstream cout ("photo.out");
	ifstream cin ("photo.in");
 	
 	int n;
 	cin>>n;
 	
 	vi b(n-1);
 	for(int&q : b) cin>>q;
 	
 	for(int i=1; i<=n; ++i) {
		si used={i};
		vi a(n);
		a[0]=i;
		bool good=true;
		for(int j=0; j<n-1 && good; ++j) {
			a[j+1]=b[j]-a[j];
			if(used.count(a[j+1]) || a[j+1]>n) good=false;
			else used.insert(a[j+1]);
		}
		if(good) {
			for(int k=0; k<n-1; ++k) cout<<a[k]<<" ";
			cout<<a.back()<<"\n";
			return 0;
		}
	}
}

