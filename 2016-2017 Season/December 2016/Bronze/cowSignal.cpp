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
	
	ofstream cout ("cowsignal.out");
	ifstream cin ("cowsignal.in");
	
	int m,n,k;
	cin>>m>>n>>k;
	
	for(int j=0; j<m; ++j) {
		string s="";
		for(int i=0; i<n; ++i) {
			char c;
			cin>>c;
			for(int x=0; x<k; ++x) s+=c;
		}
		for(int y=0; y<k; ++y) cout<<s<<"\n";
	}
	
	return 0;
}

