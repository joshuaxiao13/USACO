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
	
	ofstream cout ("shell.out");
	ifstream cin ("shell.in");
 	
 	int n;
 	cin>>n;
 	
 	vector<tuple<int,int,int>> guess;
 	
 	for(int i=0; i<n; ++i) {
		int a,b,g;
		cin>>a>>b>>g;
		guess.pb(make_tuple(a,b,g));
	}
 	
 	int ans=0;
 	
 	for(int i=0; i<3; ++i) {
		vi shell(3,0);
		shell[i]=1;
		int correct=0;
		for(int j=0; j<n; ++j) {
			int a,b,g;
			tie(a,b,g)=guess[j];
			swap(shell[a-1],shell[b-1]);
			if(shell[g-1]) ++correct;
		}
		ans=max(ans,correct);
	}
 	
 	cout<<ans<<"\n";
	return 0;
}

