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
	
	ofstream cout ("hoofball.out");
	ifstream cin ("hoofball.in");
 	
 	int n;
 	cin>>n;
 	
 	if(n==1) {
		cout<<"1\n";
		return 0;
	}
	
 	vi pos(n);
 	vector<char> pass(n);
 	for(int&q : pos) cin>>q;
 	
 	sort(pos.begin(), pos.end());
 	
 	pass[0]='R';
 	pass[n-1]='L';
 	
 	for(int i=1; i<n-1; ++i) {
		if(abs(pos[i]-pos[i+1])<abs(pos[i]-pos[i-1])) pass[i]='R';
		else pass[i]='L';
	}
	
	vi divs={0};
	
	for(int i=0; i<n-1; ++i) {
		if(pass[i]=='L' && pass[i+1]=='R') {
			divs.pb(i+1);
		}
	}
	
	divs.pb(n);

	int ans=0;
	for(int i=0; i<int(divs.size())-1; ++i) {
		for(int j=divs[i]; j<divs[i+1]; ++j) {
			if(pass[j]=='R' && pass[j+1]=='L') {

				int pointingLeft=divs[i+1]-(j+1);
				int pointingRight=j+1-divs[i];
				if(pointingLeft>1 && pointingRight>1) ans+=2;
				else ++ans;
				break;
			}
		}
	}
	
	cout<<ans<<"\n";
	return 0;
}
