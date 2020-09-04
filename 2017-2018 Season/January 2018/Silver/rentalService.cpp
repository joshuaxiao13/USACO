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

int N, M, R;
ll output[100001], rent[100001];
vector<pair<ll,ll>> store;
vl cow, farm;

bool cmp(pi a, pi b) {

	if(a.s==b.s) return a.f>b.f;
	else return a.s>b.s;
}

ll sellToStore(ll gallons) {
	
	ll profit = 0;
	pair<ll,ll> p = make_pair(gallons, 0);
	int idx = ub(store.begin(), store.end(), p)-store.begin();
	--idx;
	
	profit += store[idx].s;
	gallons -= store[idx].f;
	
	if(gallons && idx+1<=M) profit += gallons*((store[idx+1].s-store[idx].s)/(store[idx+1].f-store[idx].f));	//gallons*rate

	return profit;
}
 
int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("rental.in");
	ofstream cout ("rental.out");

	cin >> N >> M >> R;
	cow.resize(N);
	store.resize(M);
	farm.resize(R);
	
	for(int i=0; i<N; ++i) cin >> cow[i];
	for(int i=0; i<M; ++i) cin >> store[i].f >> store[i].s;
	for(int i=0; i<R; ++i) cin >> farm[i];
	
	sort(cow.begin(), cow.end());
	sort(store.begin(), store.end(), cmp);
	sort(farm.rbegin(), farm.rend());
	
	store.insert(store.begin(), make_pair(0,0));
	
	for(int i=1; i<=N; ++i) output[i] = cow[i-1] + output[i-1];
	for(int i=1; i<=R; ++i) rent[i] = farm[i-1] + rent[i-1];
	for(int i=1; i<=M; ++i) {
		store[i].s *= store[i].f;
		store[i].s += store[i-1].s;
		store[i].f += store[i-1].f;
	}
	
	ll ans=0;
	
	//k = number of cows rented to farms
	for(int k=0; k<=min(N, R); ++k) {
		ll profit = rent[k] + sellToStore(output[N]-output[k]);
		ans = max(ans, profit);
	}
	
	cout << ans << '\n';
	return 0;
}
