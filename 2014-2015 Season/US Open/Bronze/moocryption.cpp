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
	
	ofstream cout ("moocrypt.out");
	ifstream cin ("moocrypt.in");
	
	int y,x;
 	cin>>y>>x;
 	
 	vector<vector<char>> pzl(y, vector<char>(x));
 	map<string,ll> m;
 	
 	
 	for(int i=0; i<y; i++) {
		for(int j=0; j<x; j++) {	
			cin>>pzl[i][j];
		}
	}
	
	for(int r=0; r<y; r++) {
		for(int c=0; c<x; c++) {	

			//N 
			if(r-2>=0) {
				if ( (pzl[r][c]!='O' && pzl[r-2][c]!='M' && pzl[r][c]==pzl[r-1][c] && pzl[r-1][c]!=pzl[r-2][c]) || (pzl[r][c]!='M' && pzl[r-2][c]!='O' && pzl[r][c]!=pzl[r-1][c] && pzl[r-1][c]==pzl[r-2][c]) ) {
				string str="";
				str.pb(pzl[r][c]);
				str.pb(pzl[r-1][c]);
				str.pb(pzl[r-2][c]);
				sort(str.begin(), str.end());
				m[str]++;
				}
			}
			//E
			if(c+2<=x-1) {
				if ( (pzl[r][c]!='O' && pzl[r][c+2]!='M' && pzl[r][c]==pzl[r][c+1] && pzl[r][c+1]!=pzl[r][c+2]) || (pzl[r][c]!='M' && pzl[r][c+2]!='O' && pzl[r][c]!=pzl[r][c+1] && pzl[r][c+1]==pzl[r][c+2]) ) {
				string str="";
				str.pb(pzl[r][c]);
				str.pb(pzl[r][c+1]);
				str.pb(pzl[r][c+2]);
				sort(str.begin(), str.end());
				m[str]++;
				}
			}
			//NE
			if(r-2>=0 && c+2<=x-1) {
				if ( (pzl[r][c]!='O' && pzl[r-2][c+2]!='M' && pzl[r][c]==pzl[r-1][c+1] && pzl[r-1][c+1]!=pzl[r-2][c+2]) || (pzl[r][c]!='M' && pzl[r-2][c+2]!='O' && pzl[r][c]!=pzl[r-1][c+1] && pzl[r-1][c+1]==pzl[r-2][c+2]) ) {
				string str="";
				str.pb(pzl[r][c]);
				str.pb(pzl[r-1][c+1]);
				str.pb(pzl[r-2][c+2]);
				sort(str.begin(), str.end());
				m[str]++;
				}
			}
			//SE
			if(r+2<=y-1 && c+2<=x-1) {
				if ( (pzl[r][c]!='O' && pzl[r+2][c+2]!='M' && pzl[r][c]==pzl[r+1][c+1] && pzl[r+1][c+1]!=pzl[r+2][c+2]) || (pzl[r][c]!='M' && pzl[r+2][c+2]!='O' && pzl[r][c]!=pzl[r+1][c+1] && pzl[r+1][c+1]==pzl[r+2][c+2] ) ) {
				string str="";
				str.pb(pzl[r][c]);
				str.pb(pzl[r+1][c+1]);
				str.pb(pzl[r+2][c+2]);
				sort(str.begin(), str.end());
				m[str]++;
				}
			}
		}
	}
	
	ll ans=0;
	
	for(auto x: m)
		ans=max(x.s, ans);
		
 	cout<<ans<<"\n";
	return 0;
}
