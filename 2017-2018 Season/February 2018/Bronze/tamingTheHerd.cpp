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
	
	ofstream cout ("taming.out");
	ifstream cin ("taming.in");
	
 	int n;
 	cin>>n;
 	
 	vi day(n);
 	for(int&q : day) cin>>q;
 	
 	if(day[0]>0) {
		cout<<"-1\n";
		return 0;
	}
	
	else day[0]=0;
 	
 	for(int i=1; i<n; ++i) {
		if(day[i]>0) {
			for(int j=1; j<=day[i]; j++) {
				
				if(i-j<0 || (day[i-j]!=-1 && day[i-j]!=day[i-j+1]-1)) {
					cout<<"-1\n";
					return 0;
				}
				
				else day[i-j]=day[i-j+1]-1;
			} 
		}
	}
	
	int count0=0;
	int countNeg=0;
	
	for(auto x: day) {
		if(x==0) ++count0;
		else if(x==-1) ++countNeg;
	}

 	cout<<count0<<" "<<countNeg+count0<<"\n";
	return 0;
}
