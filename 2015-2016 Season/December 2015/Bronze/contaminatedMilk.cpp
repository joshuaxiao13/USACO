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
	
	ofstream cout ("badmilk.out");
	ifstream cin ("badmilk.in");
	
	int N, M, D, S;
	cin>>N>>M>>D>>S;
	
	set<int> drink[M+1];
	vector<vi> time(M+1, vi(N+1,101));
	vector<pi> sick(S);
	
	for(int i=0; i<D; i++) {
		int p, m, t;
		cin>>p>>m>>t;
		time[m][p]=min(time[m][p], t);
		drink[m].insert(p);
	} 
	
	for(int i=0; i<S; i++) {
		int p, t;
		cin>>p>>t;
		sick[i]={p,t};
	}
	
	int ans=0;
	
	for(int i=1; i<=M; i++) {
		
		int count=0;
		
		for(auto x: sick) {
			if(time[i][x.f]<x.s) ++count;
			else break;
		}
		
		if(count==int(sick.size()))
			ans=max(ans, int(drink[i].size()));
	}

	cout<<ans<<"\n";
	return 0;
}

