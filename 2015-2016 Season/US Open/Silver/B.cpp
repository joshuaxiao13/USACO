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

int n, k;
vi d;

vi getLeftMost() {
	
	vi v(n);
	int j=0;
	
	for(int i=0; i<n; ++i) {
		while(j<n && d[j]<d[i]-k) ++j;
		v[i]=j;
	}
	
	for(int i=0; i<n; ++i) {
		v[i]=i-v[i]+1;
		if(i>0) v[i]=max(v[i], v[i-1]);
	}
	
	return v;
}

vi getRightMost() {

	vi v(n);
	int j=n-1;
	
	for(int i=n-1; i>=0; --i) {
		while(j>=0 && d[j]>d[i]+k) --j;
		v[i]=j;
	}
	
	for(int i=n-1; i>=0; --i) {
		v[i]=v[i]-i+1;
		if(i<n-1) v[i]=max(v[i], v[i+1]);
	}
	
	return v;
}
 
int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("diamond.in");
	ofstream cout ("diamond.out");
	
	cin >> n >> k;
	d.resize(n);
	for(int&q : d) cin >> q;
	
	sort(d.begin(), d.end());
	
	vi left = getLeftMost();
	vi right = getRightMost();
	
	int ans=0;
	
	for(int i=0; i<n-1; ++i) ans=max(ans, left[i]+right[i+1]);
	
	cout << ans << '\n';
	return 0;
}
