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

int g[1001][1001];
 
int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("paintbarn.in");
	ofstream cout ("paintbarn.out");
	
	int N, K;
	cin >> N >> K;
	
	// 2-D prefix sums
	while(N--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		++g[x1][y1];
		++g[x2][y2];
		--g[x1][y2];
		--g[x2][y1];
	}
	
	int ans = 0;
	
	for(int j = 0; j <= 1000; ++j) {
		for(int i = 0; i <= 1000; ++i) {
			if(i) g[j][i] += g[j][i-1];
			if(j) g[j][i] += g[j-1][i];
			if(i && j) g[j][i] -= g[j-1][i-1];
			if(g[j][i] == K) ++ans;
		}
	}
	
	cout << ans << '\n';
	return 0;
}
