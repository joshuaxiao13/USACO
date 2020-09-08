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

vector<tuple<ll, int, ll>> cow;
 
int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("convention2.in");
	ofstream cout ("convention2.out");
	
	int N;
	cin >> N;
	cow.resize(N);
	
	for(int i = 0; i < N; ++i) {
		ll a, t;
		cin >> a >> t;
		cow[i] = make_tuple(a, t, i);
	}
	
	sort(cow.begin(), cow.end());
		
	priority_queue<tuple<int, ll, ll>, vector<tuple<int, ll, ll>>, greater<tuple<int, ll, ll>>> q;
	
	ll ans = 0, prev = 0;
	
	for(int i = 0; i < N; ++i) {
		
		ll a, t;
		int seniority;
		tie(a, t, seniority) = cow[i];
		q.push(make_tuple(seniority, a, t));
		
		while(i + 1 < N && get<0>(cow[i+1]) <= prev) {
			++i;
			tie(a, t, seniority) = cow[i];
			q.push(make_tuple(seniority, a, t));
		}
		
		ll arrival = get<1>(q.top()), duration = get<2>(q.top());
		q.pop();
		
		if(prev <= arrival) prev = arrival + duration;
		else {
			ans = max(ans, prev - arrival);
			prev += duration;
		}
	}
	
	cout << ans << '\n';
	return 0;
}
