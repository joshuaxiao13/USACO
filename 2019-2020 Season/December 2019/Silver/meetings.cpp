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

int N, L;
int sumOfWeights = 0;
int w[50000];

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("meetings.in");
	ofstream cout ("meetings.out");
	
	//plan: 1. find time at which condition is satisfied, 2. find total interactions
	
	cin >> N >> L;
	vpi cow(N);
	vi left, right;
	
	for(int i = 0; i < N; ++i) {
		int weight, s, d;
		cin >> weight >> s >> d;
		sumOfWeights += a;
		cow[i] = {s, weight};	//pos, weight
		if(d == -1) left.pb(s);
		else right.pb(s);
	}
	
	sort(cow.begin(), cow.end());
	sort(left.begin(), left.end());
	sort(right.begin(), right.end());
	
	for(int i = 0; i < N; ++i) w[i] = get<2>(cow[i]);
	
	vpi arrival;
	
	for(int i = 0; i < N; ++i) {
		for(auto x : left) {
			arrival.pb({x, w[i]});
			++i;
		}
		for(auto x : right) {
			arrival.pb({L - x, w[i]});
			++i;
		}
	}
	
	sort(arrival.begin(), arrival.end());
	
	int time, cnt = 0;
	for(int i = 0; i < N; ++i) {
		time = arrival[i].f;
		cnt += arrival[i].s;
		while(i + 1 < N && arrival[i+1].f == time) ++i, cnt += arrival[i].s;
		if(2*cnt >= sumOfWeights) break;
	}
	
	int ans = 0;
	
	for(auto x : right) {
		auto it1 = lb(left.begin(), left.end(), x);
		if(it1 == left.end()) continue;
		auto it2 = ub(left.begin(), left.end(), x + 2*time);
		--it2;
		ans += (it2 - it1) + 1;
	}
	
	cout << ans << '\n';
	return 0;
}

