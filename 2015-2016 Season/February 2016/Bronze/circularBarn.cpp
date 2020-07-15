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
	
	ofstream cout ("cbarn.out");
	ifstream cin ("cbarn.in");
 	
 	int n;
 	cin>>n;
 	
 	vi r(n);
 	for(int&j : r) cin>>j;
 	
 	int ans = INT_MAX;
 	
 	for(int i=0; i<n; ++i) {
		int temp=0;
		int pos=i;
		
		for(int k=1; k<n; ++k) {
			pos%=n;
			temp+=k*(r[pos++]);
		}
		ans=min(temp,ans);
	}
 	
 	cout<<ans<<"\n";
	return 0;
}
