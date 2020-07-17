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
	
	ofstream cout ("blocks.out");
	ifstream cin ("blocks.in");
	
	int n;
	cin>>n;
	vector<vi> v(n, vi(26,0));
	
	for(int i=0; i<n; ++i) {
		vi w1(26,0), w2(26,0);
		
		string a,b;
		cin>>a>>b;
		
		for(char c: a) ++w1[c-'a'];
		for(char c: b) ++w2[c-'a'];
		for(int idx=0; idx<26; ++idx) v[i][idx]=max(w1[idx],w2[idx]);
	}
	
	for(int letter=0; letter<26; ++letter) {
		int ans=0;
		for(int i=0; i<n; ++i) ans+=v[i][letter];
		cout<<ans<<"\n";
	}
	
	return 0;
}
