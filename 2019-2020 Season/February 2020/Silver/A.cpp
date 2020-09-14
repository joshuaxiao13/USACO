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

int N, M, K, cnt = 0;
int successor[100001];
bool visited[100001];
int ans[100001];

void dfs1(int a) {

	if(visited[a]) return;
	visited[a] = true;
	++cnt;
	dfs1(successor[a]);
}

void dfs2(int a) {
	
	int pos = a, finalPos = a;
	for(int i = 0; i < K % cnt; ++i) finalPos = successor[finalPos];
	ans[finalPos] = pos;
	pos = successor[pos];
	finalPos = successor[finalPos];
	
	while(pos != a) {
		ans[finalPos] = pos;
		finalPos = successor[finalPos];
		pos = successor[pos];
	}
}

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("swap.in");
	ofstream cout ("swap.out");
	
	cin >> N >> M >> K;
	
	vi afterSwap(N + 1);
	
	for(int i = 1; i <= N; ++i) afterSwap[i] = i;
	
	for(int i = 0; i < M; ++i) {
		int L, R;
		cin >> L >> R;
		reverse(afterSwap.begin() + L, afterSwap.begin() + R + 1);
	}
	
	for(int i = 1; i <= N; ++i) successor[afterSwap[i]] = i;
	
	for(int i = 1; i <= N; ++i) {
		if(!visited[i]) {
			cnt = 0;
			dfs1(i);
			dfs2(i);
		}
	}
	
	for(int i = 1; i <= N; ++i) cout << ans[i] << '\n';
	
	return 0;
}
