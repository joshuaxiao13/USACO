#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pi = pair<int, int>;
using vpi = vector<pi>;
using indexed_set = tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>;
 
const ll INF = 1e18;
const int MOD = 1e9+7;

int N, M;
vector<pair<ll,ll>> interval;

bool valid(ll D) {

	ll cnt = 0, prev;
	for(int i = 0; i < M && cnt < N; ++i) {
		ll a, b;
		tie(a, b) = interval[i];
		if(i > 0) {
			if(prev + D > a && prev + D <= b) a = prev + D;
			else if(prev + D > a) continue;
		}
		cnt += (b - a + D)/D;
		prev = ((b - a + D)/D - 1) * D + a;
	}
	
	return cnt >= N;
}
 
int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("socdist.in");
	ofstream cout ("socdist.out");
	
	cin >> N >> M;
	interval.resize(M);
	for(int i = 0; i < M; ++i) {
		cin >> interval[i].f >> interval[i].s;
	}
	
	sort(interval.begin(), interval.end());
	
	ll D = 1;
	for(ll k = (1e18)/2; k >= 1; k /= 2) {
		while(D + k <= ll(1e18) && valid(D + k)) D += k;
	}
	
	cout << D << '\n';
	return 0;
}
