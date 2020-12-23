#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define pb push_back
#define f first
#define s second
#define mp make_pair
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

const int mxN = 2500;
int n;
ll ans = 0;
vector<pair<int,int>> coord;
int up[mxN][mxN], down[mxN][mxN];

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> n;
	for(int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		coord.pb(mp(x, y));
	}
	
	sort(coord.begin(), coord.end());
	
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if(coord[j].s > coord[i].s) ++up[i][j];
			else if(coord[j].s < coord[i].s) ++down[i][j];
			up[i][j] += up[i][j-1];
			down[i][j] += down[i][j-1];
		}
	}
	
	ans = n + 1;
	
	for(int j = 0; j < n; ++j) {
		for(int i = j + 1; i < n; ++i) {
			if(coord[j].s > coord[i].s) {
				ans += (up[j][i] - up[j][j] + 1) * (down[i][i] - down[i][j] + 1);
			}
			else {
				ans += (down[j][i] - down[j][j] + 1) * (up[i][i] - up[i][j] + 1);
			}
		}
	}
	
	cout << ans << '\n';
	
	return 0;
}
