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

vector<string> node[25];

bool unproper(int n, string a, string b) {
	
	int countA=0, countB=0, countAB=0;
	
	for(int i=0; i<n; ++i) {
		bool aFound=false, bFound=false;
		for(string characteristic : node[i]) {
			if(characteristic==a) aFound=true;
			else if(characteristic==b) bFound=true;
		}
		
		if(aFound && bFound) ++countAB;
		else if(aFound) ++countA;
		else if(bFound) ++countB;
	}
	
	return countA && countB && countAB;
}
 
int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ofstream cout ("evolution.out");
	ifstream cin ("evolution.in");
	
	int n;
	cin>>n;
	set<string> all;
	
	for(int i=0; i<n; ++i) {
		int k;
		string s;
		cin>>k;
		for(int j=0; j<k; ++j) {
			cin>>s;
			node[i].pb(s);
			all.insert(s);
		}
	}
	
	for(auto it1=all.begin(); it1!=all.end(); ++it1) {
		for(auto it2=next(it1); it2!=all.end(); ++it2) {
			if(unproper(n,*it1,*it2)) {
				cout<<"no\n";
				return 0;
			}
		}
	}
 	
 	cout<<"yes\n";
	return 0;
}
