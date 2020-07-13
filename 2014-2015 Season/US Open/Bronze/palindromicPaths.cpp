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

int n;
vector<vector<char>> grid;
vector<set<string>> fromTopLeft, fromBottomRight;

void searchTop(int r, int c, string s="") {
	
	s+=grid[r][c];
	
	if(r+c==n-1) {
		fromTopLeft[r].insert(s);
		return;
	}
	
	else {
		searchTop(r+1, c, s);
		searchTop(r, c+1, s);
	}
}

void searchBottom(int r, int c, string s="") {
	
	s+=grid[r][c];
	
	if(r+c==n-1) {
		fromBottomRight[r].insert(s);
		return;
	}
	
	else {
		searchBottom(r-1, c, s);
		searchBottom(r, c-1, s);
	}
}

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ofstream cout ("palpath.out");
	ifstream cin ("palpath.in");
	
	cin>>n;
	grid.resize(n);
	fromTopLeft.resize(n);
	fromBottomRight.resize(n);
	
	for(int j=0; j<n; ++j) {
		for(int i=0; i<n; ++i) {
			char c;
			cin>>c;
			grid[j].pb(c);
		}
	}
	
	searchBottom(n-1, n-1);
	searchTop(0,0);
	
	set<string> pals;
	
	for(int i=0; i<n; i++) {
	
	auto it1=fromBottomRight[i].begin();
	auto it2=fromTopLeft[i].begin();
	
		while(it1!=fromBottomRight[i].end() && it2!=fromTopLeft[i].end()) {

			if(*it1==*it2) {
				if(pals.count(*it1)==0) pals.insert(*it1);
				++it1;
				++it2;
			}
			else if(*it1>*it2) ++it2;
			else ++it1;	
		}
	}
	
	cout<<pals.size()<<"\n";
	return 0;
}

