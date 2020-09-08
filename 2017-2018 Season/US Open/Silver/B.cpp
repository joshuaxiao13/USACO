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
	
	ifstream cin ("lemonade.in");
	ofstream cout ("lemonade.out");
	
	int N;
	cin >> N;
	vi cow(N);
	for(auto&w : cow) cin >> w;
	
	sort(cow.rbegin(), cow.rend());
	
	int ans = 0;
	while(ans<N && cow[ans]>=ans) ++ans;
	
	cout << ans << '\n';
	return 0;
}
