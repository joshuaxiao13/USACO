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
	
	ofstream cout ("diamond.out");
	ifstream cin ("diamond.in");
	
	int N,K;
	cin>>N>>K;
	vi d(N);
	for(int&j:d) cin>>j;
	
	sort(d.begin(), d.end());
	
	int ans=1;
	
	for(int i=0; i<N; i++) {
		int r=i;
		while(r<N-1 && d[r+1]<=d[i]+K) ++r;
		ans=max(ans, r-i+1);
	}
	
 	cout<<ans<<"\n";
	return 0;
}

