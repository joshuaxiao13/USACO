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

int N, M, C;
vi cow;

bool valid(int d) {
	
	int cnt = 0;
	
	for(int i = 0; i<N; ++i) {
		++cnt;
		if(cnt > M) break;
		int capacity = 1;
		int j = i;
		while(i + 1 < N && cow[i+1] <= cow[j] + d && capacity + 1 <= C) ++i, ++capacity; 
	}
	
	return cnt <= M;
}
 
int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("convention.in");
	ofstream cout ("convention.out");
	
	cin >> N >> M >> C;
	cow.resize(N);
	
	for(auto&t : cow) cin >> t;
	
	sort(cow.begin(), cow.end());
	
	int ans = 0;
	for(int k = cow[N-1] - cow[0]; k >= 1; k/=2)
		while(!valid(ans + k)) ans += k;
		
	++ans;
	
	cout << ans << '\n';
	return 0;
}
