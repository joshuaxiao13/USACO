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
	
	ofstream cout ("backforth.out");
	ifstream cin ("backforth.in");
 	
 	si vals;
 	vals.insert(0);	//no swaps - gurantees at least 1 - no net change = same bucket each day
 	vi barn1(10), barn2(10);
 	for(int&q : barn1) cin>>q;
 	for(int&q : barn2) cin>>q;
 	
 	//1 swap = use one bucket twice and 2 different buckets for other 2 days OR use one bucket 3 times and 1 bucket once
 	for(auto x : barn1)
		for(auto y: barn2)
			vals.insert(y-x);
	
	//2 swaps = use 4 different buckets
	for(int i=0; i<10; ++i)
		for(int j=i+1; j<10; ++j)
			for(int x=0; x<10; ++x)
				for(int y=x+1; y<10; ++y)
					vals.insert(barn2[y]+barn2[x]-barn1[i]-barn1[j]);
 	
 	cout<<vals.size()<<"\n";
	return 0;
}
