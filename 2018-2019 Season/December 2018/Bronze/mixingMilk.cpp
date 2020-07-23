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

void pour(int &x, int &y, int capY) {
	
	if(y+x<=capY) {
		y+=x;
		x=0;
	}
	
	else {
		x-=(capY-y);
		y=capY;
	}
}
 
int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ofstream cout ("mixmilk.out");
	ifstream cin ("mixmilk.in");
 	
 	int capA, capB, capC, a,b,c;
 	cin>>capA>>a>>capB>>b>>capC>>c;
 	
 	for(int i=0; i<100; ++i) {
		if(i%3==0) pour(a,b,capB);
		else if(i%3==1) pour(b,c,capC);
		else pour(c,a,capA);
	}
	
	cout<<a<<"\n"<<b<<"\n"<<c<<"\n";
 	
	return 0;
}
