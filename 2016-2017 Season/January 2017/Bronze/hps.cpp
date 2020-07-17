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
	
	ofstream cout ("hps.out");
	ifstream cin ("hps.in");
	
	int n;
	cin>>n;
	vpi turns;
	while(n--) {
		int a,b;
		cin>>a>>b;
		if(a!=b) turns.pb({a,b});
	}
	
	int ans=0;
	string s="123";
	
	do {  
		int player1=0;
      
		for(pi x: turns)
			if( (s[x.f-1]=='1' && s[x.s-1]=='3') || (s[x.f-1]>s[x.s-1] && (s[x.f-1]!='3' || s[x.s-1]!='1')) ) ++player1;

		ans=max(ans,player1);
        
    } while(next_permutation(s.begin(), s.end()));  
	
	cout<<ans<<"\n";
	return 0;
}
