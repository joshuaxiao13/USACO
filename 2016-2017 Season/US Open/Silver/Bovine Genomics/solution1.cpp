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
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> indexed_set;
 
const ll INF = 1e18;
const int MOD = 1e9+7;

ll choose(int n, int r) {
	
	if(n<r) return 0;
	
	ll ans=1;
	for(int i=0; i<r; ++i) ans*=n-i;
	for(int i=2; i<=r; ++i) ans/=i;
	
	return ans;
}
 
int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("cownomics.in");
	ofstream cout ("cownomics.out");
	
	int n, m;
	ll ans=0;
	cin >> n >> m;
	
	vector<string> spot(n), plain(n);
	for(auto&q: spot) cin >> q;
	for(auto&q: plain) cin >> q;
	
	vector<int> unique, notUnique;
	
	for(int i=0; i<m; ++i) {
		vector<bool> v(4,false);
		for(auto s : spot) v[M[s[i]]]=true;
		bool good=true;
		for(auto s : plain) {
			if(v[M[s[i]]]) {
				good=false;
				break;
			}
		}
		if(good) unique.pb(i);
		else notUnique.pb(i);
	}
	
	int a=unique.size(), b=notUnique.size();
	
	ans+=a*choose(b,2);
	ans+=choose(a,2)*b;
	ans+=choose(a,3);
	
	for(int i=0; i<b; ++i) {
		for(int j=i+1; j<b; ++j) {
			for(int k=j+1; k<b; ++k) {
				
				vector<vector<vi>> v(4, vector<vi>(4, vi(4, false)));
				for(auto s : spot) {
					char a=s[notUnique[i]], b=s[notUnique[j]], c=s[notUnique[k]];
					v[M[a]][M[b]][M[c]]=true;
				}
				
				bool good=true;
				for(auto s : plain) {
					char a=s[notUnique[i]], b=s[notUnique[j]], c=s[notUnique[k]];
					if(v[M[a]][M[b]][M[c]]) {
						good=false;
						break;
					}
				}
				if(good) ++ans;
			}
		}
	}

	cout << ans << '\n';
	return 0;
}
