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
	
	ofstream cout ("bcs.out");
	ifstream cin ("bcs.in");
	
	int n,k;
	cin>>n>>k;
	vi tally(k+1,0);
	vector<vector<vector<char>>> piece(k+1, vector<vector<char>>(n, vector<char>(n)));
	vector<vpi> coords(k+1);
	vector<vi> shifts(k+1, vi(4,n));	//0-down, 1-up, 2-left, 3-right
	
	for(int p=0; p<=k; ++p) {
		for(int j=0; j<n; ++j) {
			for(int i=0; i<n; ++i) {
				cin>>piece[p][j][i];
				if(piece[p][j][i]=='#') {
					tally[p]++;
					coords[p].pb({j,i});
					shifts[p][0]=min(shifts[p][0],n-1-j);
					shifts[p][1]=min(shifts[p][1], j);
					shifts[p][2]=min(shifts[p][2], i);
					shifts[p][3]=min(shifts[p][3],n-1-i);
				}
			}
		}
	}
	
	vector<vector<set<pi>>> combos(k+1);
	
	for(int p=1; p<=k; ++p) {
		
		for(int v=-1*shifts[p][1]; v<=shifts[p][0]; ++v) {
			for(int h=-1*shifts[p][2]; h<=shifts[p][3]; ++h) {
				set<pi> temp;
				for(auto x: coords[p]) {
					if(piece[0][x.f+v][x.s+h]=='#') temp.insert({x.f+v,x.s+h});
					else break;
				}
				
				if(temp.size()==coords[p].size()) combos[p].pb(temp);
			}
		}
	}
	
	for(int p1=1; p1<=k; ++p1) {
		
		if(tally[p1]>=tally[0]) continue;
		
		for(int p2=p1+1; p2<=k; ++p2) {
			
			if(tally[p1]+tally[p2]!=tally[0]) continue;

			for(auto combo1 : combos[p1]) {
				for(auto combo2 : combos[p2]) {
					
					bool ok=true;
					
					for(auto x : combo1)
						if(combo2.count(x)) {
							ok=false;
							break;
						}
					
					if(ok) {
						cout<<p1<<" "<<p2<<"\n";
						return 0;
					}
				}
			}
		}
	}
}

