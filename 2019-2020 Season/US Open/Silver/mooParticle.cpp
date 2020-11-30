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

const int mxN = 1e5;
int mnLeft[mxN], mxRight[mxN];

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("moop.in");
	ofstream cout ("moop.out");
	
	int N;
	cin >> N;
	vpi particle(N);
	for(int i = 0; i < N; ++i) cin >> particle[i].f >> particle[i].s;
	
	sort(particle.begin(), particle.end());
	
	mnLeft[0] = particle[0].s;
	mxRight[N-1] = particle[N-1].s;
	
	for(int i = 1; i < N; ++i) mnLeft[i] = min(mnLeft[i-1], particle[i].s);
	for(int i = N - 2; i >= 0; --i) mxRight[i] = max(mxRight[i+1], particle[i].s);
	
	int ans = 1;
	for(int i = 0; i < N-1; ++i) {
		if(mnLeft[i] > mxRight[i+1]) ++ans;
	}
	
	cout << ans << '\n';
	return 0;
}
