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
	
	ifstream cin ("helpcross.in");
	ofstream cout ("helpcross.out");
	
	int C, N;
	cin >> C >> N;
	multiset<int> chick;
	vpi cow(N);
	
	for(int i=0; i<C; ++i) {
		int t;
		cin >> t;
		chick.insert(t);
	}
	for(int i=0; i<N; ++i) cin >> cow[i].s >> cow[i].f;
	sort(cow.begin(), cow.end());
	
	int ans=0;
	
	for(int i=0; i<N; ++i) {
		auto it = chick.lb(cow[i].s);
		if(it!=chick.end() && *it<=cow[i].f) {
			++ans;
			chick.erase(it);
		}
	}
	
	cout << ans << '\n';
	return 0;
}
