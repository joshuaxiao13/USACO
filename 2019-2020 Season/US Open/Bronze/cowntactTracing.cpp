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

int mxK=-1, mnK=1e9;

bool valid(string s, int N, int K, int pat0, int k, vector<tuple<int,int,int>> shake) {

	vector<bool> infected(N, false);
	vi handshakes(N, 0);
	infected[pat0]=true;

	for(int i=0; i<K; ++i) {
		int x=get<1>(shake[i]), y=get<2>(shake[i]);
		
		if(infected[x]) ++handshakes[x];
		if(infected[y]) ++handshakes[y];
		
		if(!infected[x] && infected[y] && handshakes[y]<=k) infected[x]=true;
		if(!infected[y] && infected[x] && handshakes[x]<=k) infected[y]=true;
		
		if(infected[x] && s[x]!='1') return false;
		if(infected[y] && s[y]!='1') return false;
	}
	
	for(int i=0; i<N; ++i) 
		if(!infected[i] && s[i]=='1') return false;
		
	mnK=min(mnK, k);
	mxK=max(mxK, k);
	return true;
}
 
int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ofstream cout ("tracing.out");
	ifstream cin ("tracing.in");
 	
 	int N,K;
 	cin>>N>>K;
 	string s;
 	cin>>s;
 	
 	vector<tuple<int,int,int>> shake(K);
 	
 	for(int i=0; i<K; ++i) {
		int t,x,y;
		cin>>t>>x>>y;
		shake[i]=(make_tuple(t,x-1,y-1));
	}
	
	sort(shake.begin(), shake.end());
	si possible;
	
	for(int pat0=0; pat0<N; ++pat0) {
		for(int k=0; k<=K; ++k) {
			if(valid(s,N,K,pat0,k,shake))
				possible.insert(pat0);
		}
	}
	
	cout<<int(possible.size())<<" "<<mnK<<" ";
	if(mxK==K) cout<<"Infinity\n";
	else cout<<mxK<<"\n";
 	
	return 0;
}
