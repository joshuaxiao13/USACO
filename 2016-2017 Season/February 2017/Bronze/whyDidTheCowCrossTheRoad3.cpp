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
	
	ofstream cout ("cowqueue.out");
	ifstream cin ("cowqueue.in");
 	
 	int n;
 	cin>>n;
 	vpi cow(n);
 	
 	for(int i=0; i<n; ++i) {
		int arrival, questioning;
		cin>>arrival>>questioning;
		cow[i]={arrival,questioning};
	}
	
	sort(cow.begin(),cow.end());
	int curTime=0;
 	
 	for(int i=0; i<n; ++i) {
		int arrival, questioning;
		tie(arrival,questioning)=cow[i];
		
		curTime=max(curTime,arrival);
		curTime+=questioning;
	}
	
	cout<<curTime<<"\n";
	return 0;
}
