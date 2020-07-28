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
	
	ofstream cout ("word.out");
	ifstream cin ("word.in");
 	
 	int n,k;
 	cin>>n>>k;
 	
 	vector<string> s(n);
 	for(string&q : s) cin>>q;
 	
 	int cnt=0;
 	for(int i=0; i<n-1; ++i) {
		cnt+=s[i].size();
		cout<<s[i];
		if(cnt+s[i+1].size()<=k) cout<<" ";
		else {
			cout<<"\n";
			cnt=0;
		}
	} 
	
	cout<<s.back();

	return 0;
}

