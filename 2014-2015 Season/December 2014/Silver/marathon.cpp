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
 
int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("marathon.in");
	ofstream cout ("marathon.out");
	
	int N, K;
	cin >> N >> K;
	int pos[N][2];
	
	for(int i=0; i<N; ++i) cin >> pos[i][0] >> pos[i][1];
	
	//dp[k][i] = min distance to reach ith checkpoint after k total skips
	
	vector<vi> dp(K+1, vi(N, 2e6));
	dp[0][0]=0;
	
	for(int s=0; s<=K; ++s) {						//s = number of skips to arrive at "from" checkpoint
		for(int from=0; from<N; ++from) {			//from = position of checkpoint visited before "to" checkpoint
			for(int to=from+1; to<N; ++to) {		//to = position of desired checkpoint after (to-from-1) skips from "from" checkpoint
				int totalSkips = s + (to-from-1);
				if(totalSkips>K) break;
				int fromToDistance = abs(pos[to][0] - pos[from][0]) + abs(pos[to][1] - pos[from][1]);
				dp[totalSkips][to] = min(dp[totalSkips][to], dp[s][from] + fromToDistance);
			}
		}
	}
	
	cout << dp[K][N-1] << '\n';
	return 0;
}
