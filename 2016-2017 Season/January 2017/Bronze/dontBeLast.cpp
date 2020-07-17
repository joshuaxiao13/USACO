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
	
	ofstream cout ("notlast.out");
	ifstream cin ("notlast.in");
	
	vector<string> names={"Bessie","Elsie","Daisy","Gertie","Annabelle","Maggie","Henrietta"};

	vpi milked(7);
	for(int i=0; i<7; ++i) milked[i]={0,i};
	int n;
	cin>>n;
	
	while(n--) {
		string name;
		int vol;
		cin>>name>>vol;
		for(int i=0; i<7; i++) {
			if(name==names[i]) {
				milked[i].f+=vol;
				break;
			}
		}
	}
	
	sort(milked.begin(),milked.end());
	
	int idx=0;
	
	while(idx+1<7 && milked[idx+1].f==milked[idx].f) ++idx;
	
	++idx;
	
	if(idx>6 || (idx+1<7 && milked[idx+1].f==milked[idx].f)) cout<<"Tie\n";
	else cout<<names[milked[idx].s]<<"\n";
	
	return 0;
}
