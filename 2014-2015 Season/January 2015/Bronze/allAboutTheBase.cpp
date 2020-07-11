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
	
	//ofstream cout ("whatbase.out");
 	//ifstream cin ("whatbase.in");

	int k;
	cin>>k;
	while(k--) {
		
		int x,y;
		cin>>x>>y;
		
		int oX=x%10;
		int oY=y%10;
		int tX=(x/10)%10;
		int tY=(y/10)%10;
		int hX=x/100;
		int hY=y/100;
		
		if(x>y) {					//base of y is larger than x
			
			for(int i=10; i<=15000; i++) {		//let i be the base of y
				
				int idx=10;
				int goal=hY*i*i+tY*i+oY;
				
				for(int j=(15000-10)/2; j>=1; j/=2)
					while(idx+j<i && goal>=hX*(idx+j)*(idx+j)+tX*(idx+j)+oX) 
						idx+=j;
				
				if(goal==hX*idx*idx+tX*idx+oX) {
					cout<<idx<<" "<<i<<"\n";
					break;
				}
			}
		}
		
		
		else {						// base of x is larger than y
		
			for(int i=10; i<=15000; i++) {		//let i be the base of x
		
				int idx=10;
				int goal=hX*i*i+tX*i+oX;
				
				for(int j=(15000-10)/2; j>=1; j/=2)
					while(idx+j<i && goal>=hY*(idx+j)*(idx+j)+tY*(idx+j)+oY) 
						idx+=j;
			
				if(goal==hY*idx*idx+tY*idx+oY) {
					cout<<i<<" "<<idx<<"\n";
					break;
				}
			}
		}
	}
	
	return 0;
}
