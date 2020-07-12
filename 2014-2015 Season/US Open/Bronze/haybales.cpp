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

struct Haybale {
	int sz, pos;
	bool operator<(const Haybale &h) {
		return pos<h.pos;
	}
};
 
int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ofstream cout ("trapped.out");
	ifstream cin ("trapped.in");
 	
 	int n;
 	cin>>n;
 	vector<Haybale> haybales;
 	
 	for(int i=0; i<n; i++) {
		Haybale hb;
		cin>>hb.sz>>hb.pos;
		haybales.pb(hb);
	}
	
	sort(haybales.begin(), haybales.end());
	
	int ans=0;
 	
 	for(int i=0; i<n-1; i++) {
		
		int left=i, right=i+1;
		int intervalDistance=haybales[right].pos-haybales[left].pos;
		bool knockedDown=true;
		
		while(knockedDown && left>=0 && right<n) {
			
			knockedDown=false;
			
			if(haybales[right].pos-haybales[left].pos>haybales[left].sz) {
				--left;
				knockedDown=true;
				continue;
			}
			
			if(haybales[right].pos-haybales[left].pos>haybales[right].sz) {
				++right;
				knockedDown=true;
				continue;
			}	
		}
		
		if(left>=0 && right<n) ans+=intervalDistance;
	}
	
	cout<<ans<<"\n";
	return 0;
}
