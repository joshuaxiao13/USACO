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
	
	ofstream cout ("guess.out");
	ifstream cin ("guess.in");
 	
 	int n;
 	cin>>n;
 	
 	vector<set<string>> animal(n);
 	set<string> all;
 	
 	for(int i=0; i<n; ++i) {
		string a;
		int k;
		cin>>a>>k;
		for(int j=0; j<k; ++j) {
			string str;
			cin>>str;
			animal[i].insert(str);
			all.insert(str);
		}
	}
	
	int ans=1;
	
	for(int i=0; i<n; ++i) {
		for(int j=i+1; j<n; ++j) {
			int temp=0;
			for(auto c: all) {
				if(animal[i].count(c) && animal[j].count(c)) ++temp;
			}
			ans=max(temp,ans);
		}
	}
	
 	cout<<ans+1<<"\n";
	return 0;
}
