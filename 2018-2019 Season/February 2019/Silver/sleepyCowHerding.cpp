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
	
	ifstream cin ("herding.in");
	ofstream cout ("herding.out");
	
	int N;
	cin >> N;
	vi v(N);
	for(auto&q : v) cin >> q;
	sort(v.begin(), v.end());
	
	int ans1 = INT_MAX, ans2;
	
	if(v[N-2] - v[0] + 1 == N - 1 && v[N-1] - v[N-2] > 2) ans1 = 2;
	else if(v[N-1] - v[1] + 1 == N - 1 && v[1] - v[0] > 2) ans1 = 2;
	else {
		int j = 0;
		for(int i = 0 ; i < N; ++i) {
			while(j + 1 < N && v[j+1] <= v[i] + N - 1) ++j;
			ans1 = min(ans1, N - (j - i + 1));
		}
	}
	
	ans2 = max(v[N-2] - v[0], v[N-1] - v[1]) - (N - 2);
	
	cout << ans1 << '\n' << ans2 << '\n';
	return 0;
}
