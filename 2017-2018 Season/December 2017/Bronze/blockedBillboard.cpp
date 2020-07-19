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
	
	ofstream cout ("billboard.out");
	ifstream cin ("billboard.in");
 	
 	vector<vi> bb(2,vi(4));
 	vi truck(4);
 	
 	for(int j=0; j<2; ++j) {
		for(int i=0; i<4; ++i) {
			cin>>bb[j][i];
		}
	}
	
	for(int&q : truck) cin>>q;
	
	vector<vi> intersect(2,vi({INT_MAX,INT_MAX,INT_MIN,INT_MIN}));
	
	for(int j=0; j<2; ++j) {
		for(int y=bb[j][1]; y<=bb[j][3]; ++y) {
			for(int x=bb[j][0]; x<=bb[j][2]; ++x) {
				if(x>=truck[0] && x<=truck[2] && y>=truck[1] && y<=truck[3]) {
					intersect[j][0]=min(x,intersect[j][0]);
					intersect[j][1]=min(y,intersect[j][1]);
					intersect[j][2]=max(x,intersect[j][2]);
					intersect[j][3]=max(y,intersect[j][3]);
				}
			}
		}
	}
	
	int ans=(bb[0][3]-bb[0][1])*(bb[0][2]-bb[0][0])+(bb[1][3]-bb[1][1])*(bb[1][2]-bb[1][0]);
	if(intersect[0][0]!=INT_MAX) ans-=(intersect[0][3]-intersect[0][1])*(intersect[0][2]-intersect[0][0]);
	if(intersect[1][0]!=INT_MAX) ans-=(intersect[1][3]-intersect[1][1])*(intersect[1][2]-intersect[1][0]);
 	
 	cout<<ans<<"\n";
	return 0;
}
