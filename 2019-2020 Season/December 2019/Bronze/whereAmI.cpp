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

int valid(string s, int n, int len) {
	
	set<string> m;
	
	for(int i=0; i<=n-len && true; ++i) {
		if(m.count(string(s.begin()+i,s.begin()+i+len))) return false;
		else m.insert(string(s.begin()+i,s.begin()+i+len));
	}
	
	return true;
}
 
int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ofstream cout ("whereami.out");
	ifstream cin ("whereami.in");
 	
 	int n;
 	string s;
 	cin>>n>>s;
 	
 	int ans=0;
 	for(int k=n/2; k>=1; k/=2)
		while(ans+k<=n && !valid(s,n,ans+k)) 
			ans+=k;
	
	++ans;
	cout<<ans<<"\n";
  	
	return 0;
}

