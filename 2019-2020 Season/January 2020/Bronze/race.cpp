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

int solve(int k, int v) {
	
	int time=0, dis=0;
	
	for(ll i=1; ; ++i) {
		dis+=i;
		++time;
		if(dis>=k) break;
		
		if(i>=v) {
			dis+=i;
			++time;
			if(dis>=k) break;
		}
	}
	
	return time;
}
 
int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ofstream cout ("race.out");
	ifstream cin ("race.in");
 	
 	int k,n;
 	cin>>k>>n;
 	
 	while(n--) {
		int v;
		cin>>v;
		cout<<solve(k,v)<<"\n";
	}

	return 0;
}
