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
	
	ofstream cout ("sleepy.out");
	ifstream cin ("sleepy.in");
 	
 	int n;
 	cin>>n;
 	vi v(n);
 	for(int&q: v) cin>>q;
		
 	int ans=n-1;
 	
 	while(ans>0 && v[ans-1]<v[ans]) --ans;
 	
 	cout<<ans<<"\n";
	return 0;
}

