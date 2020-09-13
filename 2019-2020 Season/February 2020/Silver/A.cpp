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

int N, K, mod;
vi B;

bool cmp(int a, int b) {
	
	return a%mod > b%mod;
}
 
int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("berries.in");
	ofstream cout ("berries.out");
	
	int mx = 0;
	cin >> N >> K;
	assert(K % 2 == 0);
	
	B.resize(N);
	for(auto&q : B) cin >> q, mx = max(mx, q);
	
	sort(B.begin(), B.end());
	
	int ans = 0;
	
	//w = smallest size of basket in Elsie's half
	for(int w = 1; w <= mx; ++w) {
		int cnt = 0;
		for(auto x : B) cnt += x/w;
		
		if(cnt < K/2) break;
		else if(cnt >= K) ans = max(ans, w*K/2);
		else {
			mod = w;
			int temp = w*(cnt - K/2);
			sort(B.begin(), B.end(), cmp);
			for(int i = 0; i < N && i < K - cnt; ++i) temp += B[i]%w;
			ans = max(ans, temp);
		} 
	}
	
	cout << ans << '\n';
	return 0;
}
