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
	
	ofstream cout ("art.out");
	ifstream cin ("art.in");
 	
 	int N;
 	cin>>N;
 	
 	vector<vi> corners(9,{11,-1,-1,11});	//i-min,j-max,i-max,j-min
 	vector<vi> pic(N,vi(N));
 	
 	for(int j=0; j<N; ++j) {
		ll a;
		cin>>a;
		for(int i=N-1; i>=0; --i) {
			pic[j][i]=a%10;
			a/=10;
			
			if(pic[j][i]==0) continue;
			
			corners[pic[j][i]-1][0]=min(corners[pic[j][i]-1][0],i);
			corners[pic[j][i]-1][1]=max(corners[pic[j][i]-1][1],j);
			corners[pic[j][i]-1][2]=max(corners[pic[j][i]-1][2],i);
			corners[pic[j][i]-1][3]=min(corners[pic[j][i]-1][3],j);

		}
	}
	
	vector<bool> possible(9, true);
	
	for(int rec1=0; rec1<9; ++rec1) {
		
		if(corners[rec1][0]==11) {
			possible[rec1]=false;
			continue;
		}
		
		for(int rec2=rec1+1; rec2<9; ++rec2) {
				
			bool rec1InfrontRec2=false;
			bool rec2InfrontRec1=false;
				
			for(int j=corners[rec1][3]; j<=corners[rec1][1] && !rec2InfrontRec1; ++j)
				for(int i=corners[rec1][0]; i<=corners[rec1][2] && !rec2InfrontRec1; ++i)
					if(pic[j][i]==rec2+1) rec2InfrontRec1=true;

				
			for(int j=corners[rec2][3]; j<=corners[rec2][1] && !rec1InfrontRec2; ++j)
				for(int i=corners[rec2][0]; i<=corners[rec2][2] && !rec1InfrontRec2; ++i)
					if(pic[j][i]==rec1+1) rec1InfrontRec2=true;

			if(rec1InfrontRec2) possible[rec1]=false;
			else if(rec2InfrontRec1)	possible[rec2]=false;
		}
	}
	
	int ans=0;
	
	for(int i=0; i<9; ++i)
		if(possible[i] && corners[i][0]!=11) ++ans;
 	
 	cout<<ans<<"\n";
	return 0;
}
