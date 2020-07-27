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
	
	ofstream cout ("lineup.out");
	ifstream cin ("lineup.in");
 	
 	int n;
 	cin>>n;
 	
 	vector<string> cow={"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
 	vector<pair<string,string>> constraint;
 	
 	while(n--) {
		string name1, name2;
		cin>>name1;
		cin.ignore(22,'\n');
		cin>>name2;
		constraint.pb({name1,name2});
	}
	
 	do {
		
		bool good=true;
		for(auto x: constraint) {
			auto it1 = find(cow.begin(),cow.end(),x.f);
			auto it2 = find(cow.begin(), cow.end(), x.s);
			if(abs(it1-it2)!=1) {
				good=false;
				break;
			}
		}
		
		if(good) {
			for(auto c : cow) cout<<c<<"\n";
			return 0;
		}
		
	} while(next_permutation(cow.begin(),cow.end()));
}

