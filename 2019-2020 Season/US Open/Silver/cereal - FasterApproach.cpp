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

const int mxN = 1e5 + 1;
int N, M, cnt = 0;
int ans[mxN], choice[mxN][2], cur[mxN];

void redistribute(int cow, int cereal) {
	
	if(cur[cereal] == 0) cur[cereal] = cow;
	else if(cur[cereal] < cow) --cnt;
	else if(choice[cur[cereal]][1] == cereal) --cnt, cur[cereal] = cow;
	else redistribute(cur[cereal], choice[cur[cereal]][1]), cur[cereal] = cow;	
}
 
int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("cereal.in");
	ofstream cout ("cereal.out");
	
	cin >> N >> M;
	for(int i = 1 ; i <= N; ++i) cin >> choice[i][0] >> choice[i][1];
	
	for(int cow = N; cow >= 1; --cow) {
		int a = choice[cow][0];
		
		if(cur[a] == 0) ++cnt, cur[a] = cow;
		else if(choice[cur[a]][1] == a) cur[a] = cow;
		else ++cnt, redistribute(cur[a], choice[cur[a]][1]), cur[a] = cow;
		
		ans[cow] = cnt;
	}
	
	for(int i = 1; i <= N; ++i) cout << ans[i] << '\n';
	
	return 0;
}
