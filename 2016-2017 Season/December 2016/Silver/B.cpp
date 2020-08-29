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
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
 
const ll INF = 1e18;
const int MOD = 1e9+7;
 
int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("citystate.in");
	ofstream cout ("citystate.out");
	
	ll ans=0;
	int n;
	cin >> n;
	vector<vector<vi>> city(26, vector<vi>(26));
	vector<vector<vi>> state(26,vector<vi>(26));
	
	for(int i=1; i<=n; ++i) {
		string a, b;
		cin >> a >> b;
		city[a[0]-'A'][a[1]-'A'].pb(i);
		state[b[0]-'A'][b[1]-'A'].pb(i);
		if(a[0]==b[0] && a[1]==b[1]) continue;
		
		vi &x=city[b[0]-'A'][b[1]-'A'];
		vi &y=state[a[0]-'A'][a[1]-'A'];
		if(x.size()==0 || y.size()==0) continue;
		
		int idx1=0, idx2=0;
		
		while(idx1<x.size() && idx2<y.size()) {
			if(x[idx1]==y[idx2]) ++ans, idx1++, idx2++;
			else if(x[idx1]<y[idx2]) ++idx1;
			else ++idx2;
		}
	}
	
	cout << ans << '\n';
	return 0;
}
