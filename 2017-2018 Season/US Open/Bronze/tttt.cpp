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
	
	ofstream cout ("tttt.out");
	ifstream cin ("tttt.in");
 	
 	vector<vector<char>> grid(3, vector<char>(3));
 	
 	for(int j=0; j<3; ++j) {
		string str;
		cin>>str;
		for(int i=0; i<3; ++i) {
			grid[j][i]=str[i];
		}
	}
	
	set<char> single;
	set<pair<char,char>> duo;
	
	//horizontals
	for(int j=0; j<3; ++j) {
		
		set<char> temp;
		temp.insert(grid[j][0]);
		temp.insert(grid[j][1]);
		temp.insert(grid[j][2]);
			
		if(temp.size()==1) 
			single.insert(*temp.begin());
			
		else if(temp.size()==2) {
			if(*temp.begin()<*--temp.end()) duo.insert({*temp.begin(),*--temp.end()});
			else duo.insert({*--temp.end(),*temp.begin()});
		}
	}
	
	//verticals
	for(int i=0; i<3; ++i) {
		
		set<char> temp;
		temp.insert(grid[0][i]);
		temp.insert(grid[1][i]);
		temp.insert(grid[2][i]);
		
		if(temp.size()==1) 
			single.insert(*temp.begin());
			
		else if(temp.size()==2) {
			if(*temp.begin()<*--temp.end()) duo.insert({*temp.begin(),*--temp.end()});
			else duo.insert({*--temp.end(),*temp.begin()});
		}
	}
	
	//diagonals
	set<char> d1;
	d1.insert(grid[0][0]);
	d1.insert(grid[1][1]);
	d1.insert(grid[2][2]);
	set<char> d2;
	d2.insert(grid[2][0]);
	d2.insert(grid[1][1]);
	d2.insert(grid[0][2]);
	
	if(d1.size()==1) single.insert(*d1.begin());
	else if(d1.size()==2) {
		if(*d1.begin()<*--d1.end()) duo.insert({*d1.begin(),*--d1.end()});
		else duo.insert({*--d1.end(),*d1.begin()});
	}
	
	if(d2.size()==1) single.insert(*d2.begin());
	else if(d2.size()==2) {
		if(*d2.begin()<*--d2.end()) duo.insert({*d2.begin(),*--d2.end()});
		else duo.insert({*--d2.end(),*d2.begin()});
	}
	
	cout<<single.size()<<"\n"<<duo.size()<<"\n";
	return 0;
}
