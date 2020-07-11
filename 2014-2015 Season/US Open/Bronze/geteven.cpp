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
	
	ofstream cout ("geteven.out");
	ifstream cin ("geteven.in");
	
	// (B+E+S+S+I+E)(G+O+E+S)(M+O+O)
 	
 	int N;
 	cin>>N;
 	
 	int bEven=0;
	int bOdd=0;
	
	int eEven=0;
	int eOdd=0;
	
	int sEven=0;
	int sOdd=0;
	
	int iEven=0;
	int iOdd=0;
	
	int gEven=0;
	int gOdd=0;
	
	int oEven=0;
	int oOdd=0;
	
	int mEven=0;
	int mOdd=0;
 	
 	while(N--) {
		
		char c;
		int a;
		
		cin>>c>>a;
		
		if(c=='B') {
			if(a%2==0) ++bEven;
			else ++bOdd;
		}
		else if(c=='E') {
			if(a%2==0) ++eEven;
			else ++eOdd;
		}
		else if(c=='S') {
			if(a%2==0) ++sEven;
			else ++sOdd;
		}
		else if(c=='I') {
			if(a%2==0) ++iEven;
			else ++iOdd;
		}
		else if(c=='G') {
			if(a%2==0) ++gEven;
			else ++gOdd;
		}
		else if(c=='O') {
			if(a%2==0) ++oEven;
			else ++oOdd;
		}
		else {
			if(a%2==0) ++mEven;
			else ++mOdd;
		}
	}
	
	// (B+I+2S+2E)(G+O+E+S)(M+2O) = (X)(Y)(Z)
	// (B+I)(G+O+E+S)(M)

	ll ans=0;
	
	ll YEven=0;
			
	for(int x=0; x<=15; x++) {
		if(__builtin_parity(x)==0) {

			ll temp=1;
					
			if(x&(1<<0)) temp*=sEven;
			else temp*=sOdd;
			if(x&(1<<1)) temp*=eEven;
			else temp*=eOdd;
			if(x&(1<<2)) temp*=oEven;
			else temp*=oOdd;
			if(x&(1<<3)) temp*=gEven;
			else temp*=gOdd;
			
			YEven+=temp;
		}
	}
	
	ll YOdd = (gEven+gOdd)*(oEven+oOdd)*(eEven+eOdd)*(sEven+sOdd)-YEven;
	
	ll XEven = bOdd*iOdd + bEven*iEven;
	ll XOdd = (bOdd+bEven)*(iOdd+iEven)-XEven;

	for(int i=1; i<=7; i++) {
		
		ll temp=1;
		
		if(i&(1<<0)) temp*=mEven;
		else temp*=mOdd;
		
		if(i&(1<<2)) temp*=XEven;
		else temp*=XOdd;
		
		if(i&(1<<1)) temp*=YEven;
		else temp*=YOdd;
			
		ans+=temp;
	}
	
 	cout<<ans<<"\n";
	return 0;
}

