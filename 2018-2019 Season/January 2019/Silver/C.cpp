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

bool cmp(pi a, pi b) {
	
	if(a.f == b.f) return a.s > b.s;
	return a.f < b.f;
}
 
int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("mountains.in");
	ofstream cout ("mountains.out");
	
	int N;
	cin >> N;
	vpi mountain(N);
	
	for(int i = 0; i < N; ++i) {
		int x, y;
		cin >> x >> y;
		mountain[i].f = x - y;
		mountain[i].s = x + y;
	}
	
	sort(mountain.begin(), mountain.end(), cmp);
	
	int ans = 1;
	int hi = mountain[0].s;
	
	for(int i = 1; i<N; ++i) {
		int lhs, rhs;
		tie(lhs, rhs) = mountain[i];
		if(lhs > hi || rhs > hi) ++ans, hi = rhs;
	}
	
	cout << ans << '\n';
	return 0;
}
