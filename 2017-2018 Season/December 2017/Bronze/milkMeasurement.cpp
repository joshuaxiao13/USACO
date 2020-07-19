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
	
	ofstream cout ("measurement.out");
	ifstream cin ("measurement.in");
 	
 	vector<string> cowName={"Bessie", "Elsie", "Mildred"};
 	vi output(3,7);
 	int n;
 	cin>>n;
 	vector<tuple<int,int,int>> recording;
 	
 	for(int i=0; i<n; ++i) {
		int day, delta;
		string name;
		cin>>day>>name>>delta;
		for(int j=0; j<3; ++j) {
			if(name==cowName[j]) {
				recording.pb(make_tuple(day,j,delta));
			}
		}
	}
	
	sort(recording.begin(),recording.end());
	int ans=0;
	vector<bool> onDisplay(3,false);
	
	for(int i=0; i<n; ++i) {
		int day,cow,delta;
		tie(day,cow,delta)=recording[i];
		output[cow]+=delta;
		
		int outputMax=max(max(output[0],output[1]),output[2]);
		bool changed=false;
		
		for(int j=0; j<3; ++j) {
			if(output[j]==outputMax) {
				if(!onDisplay[j]) {
					onDisplay[j]=true;
					changed=true;
				}
			}
			else {
				if(onDisplay[j]) {
					changed=true;
					onDisplay[j]=false;
				}
			}
		}
		
		if(changed) ++ans;
	}
 	
 	cout<<ans<<"\n";
	return 0;
}
