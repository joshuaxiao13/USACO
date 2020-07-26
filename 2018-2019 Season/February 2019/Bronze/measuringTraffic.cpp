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
	
	ofstream cout ("traffic.out");
	ifstream cin ("traffic.in");
 	
 	int n;
 	cin>>n;
 	vector<tuple<string,int,int>> sensor;
 	
 	for(int i=0; i<n; ++i) {
		string type;
		int left, right;
		cin>>type>>left>>right;
		sensor.pb(make_tuple(type,left,right));
	}
	
	int lowBound=-999999, upBound=999999;
	
	for(int i=n-1; i>=0; --i) {
		string type;
		int left,right;
		tie(type,left,right)=sensor[i];
		
		if(type=="none") {
			lowBound=max(lowBound,left);
			upBound=min(upBound,right);
		}
		
		else if(type=="on") {
			lowBound=lowBound-right>0?lowBound-right:0;
			upBound-=left;
		}
		
		else {
			lowBound+=left;
			upBound+=right;
		}
	}	
	
	cout<<lowBound<<" "<<upBound<<"\n";
		
	
	lowBound=-999999, upBound=999999;
 	
 	for(int i=0; i<n; ++i) {
		string type;
		int left,right;
		tie(type,left,right)=sensor[i];
		
		if(type=="none") {
			lowBound=max(lowBound,left);
			upBound=min(upBound,right);
		}
		
		else if(type=="off") {
			lowBound=lowBound-right>0?lowBound-right:0;
			upBound-=left;
		}
		
		else {
			lowBound+=left;
			upBound+=right;
		}
	}	
 	
 	cout<<lowBound<<" "<<upBound<<"\n";
	return 0;
}
