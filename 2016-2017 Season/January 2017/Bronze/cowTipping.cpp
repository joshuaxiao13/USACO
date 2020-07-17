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

int ans=0;

void flip(vector<vi> &farm, int x, int y) {
	
	for(int j=0; j<=y; ++j) {
		for(int i=0; i<=x; ++i) {
			if(farm[j][i]==1) farm[j][i]=0;
			else farm[j][i]=1;
		}
	}
}

void solve(vector<vi> &farm, int x, int y) {
	
	if(x<0 && y<0) return;
	
	bool clearHor=true, clearVert=true;
	
	for(int j=0; j<=y && clearVert; ++j)
		if(farm[j][x]!=0) clearVert=false;
	
	for(int i=0; i<=x && clearHor; i++)
		if(farm[y][i]!=0) clearHor=false;

	for(int i=x; i>=0 && !clearHor; --i)
		if(farm[y][i]==1) {
			flip(farm, i, y);
			++ans;
		}
		
	for(int j=y; j>=0 && !clearVert; --j)
		if(farm[j][x]==1) {
			flip(farm, x, j);
			++ans;
		}
		
	solve(farm,x-1,y-1);
}

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ofstream cout ("cowtip.out");
	ifstream cin ("cowtip.in");
	
	int n;
	cin>>n;
	vector<vi> farm(n, vi(n));
	
	for(int j=0; j<n; ++j) {
		int num;
		cin>>num;
		for(int i=n-1; i>=0; --i) {
			farm[j][i]=num%10;
			num/=10;
		}
	}
	
	solve(farm,n-1,n-1);
	
	cout<<ans<<"\n";
	return 0;
}
