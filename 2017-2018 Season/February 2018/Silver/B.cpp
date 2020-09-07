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
	
	ifstream cin ("snowboots.in");
	ofstream cout ("snowboots.out");
	
	int N, B;
	cin >> N >> B;
	
	vi tile(N);
	vpi boot(B+1);
	
	for(auto&q : tile) cin >> q;
	for(int i=1; i<=B; ++i) cin >> boot[i].f >> boot[i].s;
	
	vector<vector<bool>> visited(N, vector<bool>(B+1, false)); 	//visited[i][j] = visited ith tile with jth boot (i is 0-indexed, j is not)
	priority_queue<pi, vpi, greater<pi>> q;
	q.push({1,0});
	
	while(!q.empty()) {
		int bootNum, pos;
		tie(bootNum, pos) = q.top();
		q.pop();
		
		if(pos == N-1) {
			cout << bootNum - 1 << '\n';
			break;
		}
		
		if(visited[pos][bootNum]) continue;
		visited[pos][bootNum] = true;
		
		//discard boot, put on next boots
		for(int b = 1; bootNum+b<=B; ++b) {
			if(boot[bootNum+b].f>=tile[pos]) q.push({bootNum+b, pos});
		}
		
		int maxDepth, maxSteps;
		tie(maxDepth, maxSteps) = boot[bootNum];
		
		//keep boot, step forward
		for(int k = 1; k<=maxSteps && pos+k<N; ++k) {
			if(maxDepth>=tile[pos+k]) q.push({bootNum, pos+k});
		}
	}
	
	return 0;
}
