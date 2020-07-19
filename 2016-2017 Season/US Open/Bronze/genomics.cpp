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
	
	ofstream cout ("cownomics.out");
	ifstream cin ("cownomics.in");
 	
 	int N,M;
 	cin>>N>>M;
 	vector<vector<si>> data(2, vector<si>(M));
 	
 	for(int k=0; k<2; ++k) {
		for(int j=0; j<N; ++j) {
			for(int i=0; i<M; ++i) {
				char c;
				cin>>c;
				data[k][i].insert(c);
			}
		}
	}
	
	int ans=0;
	
	for(int i=0; i<M; ++i) {
		bool good=true;
		
		for(auto x: data[0][i]) {
			if(data[1][i].count(x)) {
				good=false;
				break;
			}
		}
		
		if(good) ++ans;
	}
 	
 	cout<<ans<<"\n";
	return 0;
}
