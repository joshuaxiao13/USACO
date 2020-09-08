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
	
	ifstream cin ("sort.in");
	ofstream cout ("sort.out");
	
	map<int,queue<int>> m;
	int N;
	cin >> N;
	vi v(N);
	for(int i=0; i<N; ++i) {
		cin >> v[i], m[v[i]].push(i);
	}
	vi sorted = v;
	
	sort(sorted.begin(), sorted.end());
	int ans = 0;
	
	for(int i=0; i<N; ++i) {
		if(m[sorted[i]].front()>i) ans = max(ans, m[sorted[i]].front() - i);
		m[sorted[i]].pop();
	}
	
	cout << ans + 1 << '\n';
	return 0;
}
