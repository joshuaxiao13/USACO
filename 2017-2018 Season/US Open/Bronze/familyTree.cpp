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
	
	ofstream cout ("family.out");
	ifstream cin ("family.in");
 	
 	int n;
 	string a,b;
 	cin>>n>>a>>b;

 	map<string,string> motherOf; //map child to mother
 	
 	for(int i=0; i<n; ++i) {
		string mother, child;
		cin>>mother>>child;
		motherOf[child]=mother;
	}
	
	vector<string> aLine;
	vector<string> bLine;
	
	string aTemp=a;
	do {
		aLine.pb(aTemp);
		aTemp=motherOf[aTemp];
		
	} while(aTemp!="");
	
	string bTemp=b;
	do {
		bLine.pb(bTemp);
		bTemp=motherOf[bTemp];
		
	} while(bTemp!="");
	
	//should share a common node if related
	if(aLine.back()!=bLine.back()) {
		cout<<"NOT RELATED\n";
		return 0;
	}
	
	while(aLine.size()>0 && bLine.size()>0 && aLine.back()==bLine.back()) {
		aLine.pop_back();
		bLine.pop_back();
	}

	//if great/grand/mother/direct descendant
	if(aLine.size()==0 || bLine.size()==0) {
		if(aLine.size()==0) {
			if(bLine.size()==1) cout<<a<<" is the mother of "<<b<<"\n";
			else {
				string addIn="";
				for(int i=0; i<int(bLine.size()-2); ++i) addIn+="great-";
				addIn+="grand-mother";
				cout<<a<<" is the "<<addIn<<" of "<<b<<"\n";
			}
		}
		
		else {
			if(aLine.size()==1) cout<<b<<" is the mother of "<<a<<"\n";
			else {
				string addIn="";
				for(int i=0; i<int(aLine.size()-2); ++i) addIn+="great-";
				addIn+="grand-mother";
				cout<<b<<" is the "<<addIn<<" of "<<a<<"\n";
			}
		}
	}
	
	//if siblings (same mother)
	else if(aLine.size()==1 && bLine.size()==1) {
		cout<<"SIBLINGS\n";
	}
	
	//if ancestor/aunt
	else if(aLine.size()==1 || bLine.size()==1) {
		if(aLine.size()==1) {
			string addIn="";
			for(int i=0; i<int(bLine.size()-2); ++i) addIn+="great-";
			addIn+="aunt";
			cout<<a<<" is the "<<addIn<<" of "<<b<<"\n";
		}
		
		else {
			string addIn="";
			for(int i=0; i<int(aLine.size()-2); ++i) addIn+="great-";
			addIn+="aunt";
			cout<<b<<" is the "<<addIn<<" of "<<a<<"\n";
		}
	}
	
	//if cousins
	else cout<<"COUSINS\n";
	
	return 0;
}
