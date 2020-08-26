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
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef set<int> si;
typedef multiset<int> mi;
 
const ll INF = 1e18;
const int MOD = 1e9+7;

int n;
vpi cow;
vi y, x;

bool valid(int xMn, int xMx, int yMn, int yMx) {
	
	int cnt=0;
	
	for(auto c : cow) {
		int i, j;
		tie(i, j)=c;
		
		if(!(i>=x[xMn] && i<=x[xMx] && j>=y[yMn] && j<=y[yMx])) {
			++cnt;
			if(cnt>3) return false;
		}
	}
	
	return true;
}

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("reduce.in");
	ofstream cout ("reduce.out");
	
	cin >> n;
	cow.resize(n);
	y.resize(n);
	x.resize(n);
	
	for(int i=0; i<n; ++i) {
		cin >> cow[i].f >> cow[i].s;
		y[i]=cow[i].s;
		x[i]=cow[i].f;
	}
	
	if(n<=4) {
		cout << "0\n";
		return 0;
	}
	
	sort(y.begin(), y.end());
	sort(x.begin(), x.end());
	
	int ans=INT_MAX;
	
	for(int xMn=0; xMn<4; ++xMn) {
		for(int xMx=n-1; xMx>n-5; --xMx) {
			
			if(xMn>xMx) break;
			
			for(int yMn=0; yMn<4; ++yMn) {
				for(int yMx=n-1; yMx>n-5; --yMx) {
					
					if(yMn>yMx) break;
					
					if(valid(xMn, xMx, yMn, yMx)) {
						int area=(x[xMx]-x[xMn])*(y[yMx]-y[yMn]);
						ans=min(ans, area);
					}					
				}
			}
		}
	}
	
	cout << ans << "\n";
	return 0;
}
