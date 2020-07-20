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
	
	vector<vi> bb(2, vi(4));
	
	for(int j=0; j<2; ++j) {
		for(int i=0; i<4; ++i) {
			cin>>bb[j][i];
		}
	}
	
	vi intersection={INT_MAX,INT_MIN,INT_MAX,INT_MIN};
	
	for(int j=bb[0][1]; j<=bb[0][3]; ++j) {
		for(int i=bb[0][0]; i<=bb[0][2]; ++i) {
			if(i>=bb[1][0] && i<=bb[1][2] && j>=bb[1][1] && j<=bb[1][3]) {
				intersection[0]=min(i, intersection[0]);
				intersection[1]=max(i, intersection[1]);
				intersection[2]=min(j, intersection[2]);
				intersection[3]=max(j, intersection[3]);
			}			
		}
	}
	
	int areaTotal=(bb[0][2]-bb[0][0])*(bb[0][3]-bb[0][1]);
	
	if( (intersection[2]==bb[0][1] && intersection[3]==bb[0][3] && (intersection[0]==bb[0][0] || intersection[1]==bb[0][2])) || (intersection[0]==bb[0][0] && intersection[1]==bb[0][2] && (intersection[2]==bb[0][1] || intersection[3]==bb[0][3])) )
		cout<<areaTotal-(intersection[1]-intersection[0])*(intersection[3]-intersection[2])<<"\n";

	else cout<<areaTotal<<"\n";
 	
	return 0;
}
