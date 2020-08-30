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

ll n, tMx;
vl cow;

bool valid(int k) {
	
	priority_queue<ll, vl, greater<ll>> q;
	
	for(int i=0; i<k && i<n; ++i) q.push(cow[i]);
	
	for(int i=k; i<n; i+=k) {
		for(int j=i; j<n && j<i+k; ++j) {
			ll a=q.top();
			q.pop();
			q.push(a+cow[j]);
		}
	}
	
	while(--k) q.pop();
	if(q.top()>tMx) return false;
	else return true;
	
}
 
int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("cowdance.in");
	ofstream cout ("cowdance.out");
	
	cin >> n >> tMx;
	
	cow.resize(n);
	for(ll&q : cow) cin >> q;
	
	int ans=1;
	for(int k=n/2; k>=1; k/=2)
		while(ans+k<=n && !valid(ans+k)) 
			ans+=k;
	
	++ans;
	cout << ans << '\n';
	
	return 0;
}
