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

const ll inc = 1e4;
ll N;
vl yAtXEquals[20001], xAtYEquals[20001];	//yAtXEquals[i] stores all y-coordinates of points on x = i
vl sumOfY[20001], sumOfX[20001];			//sumOfY[i] = sum of x-coordinates of points on y = i
vector<pair<ll,ll>> pole;
 
int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("triangles.in");
	ofstream cout ("triangles.out");
	
	cin >> N;
	
	for(int i = 0; i < N; ++i) {
		ll x, y;
		cin >> x >> y;
		pole.pb({x, y});
	}
	
	sort(pole.begin(), pole.end());
	
	for(auto p : pole) {
		ll x, y;
		tie(x, y) = p;
		xAtYEquals[y + inc].pb(x);
		yAtXEquals[x + inc].pb(y);
	}
	
	for(int i = 0; i < 20001; ++i) {
		vl &a = yAtXEquals[i], &b = xAtYEquals[i];
		
		if(!a.empty()) {
			ll temp = 0;
			for(auto y : a) {
				temp += y;
				sumOfY[i].pb(temp);
			}
		}
		if(!b.empty()) {
			ll temp = 0;
			for(auto x : b) {
				temp += x;
				sumOfX[i].pb(temp);
			}
		}
	}
	
	ll ans = 0;
	
	for(auto p : pole) {
		ll i, j, sumVertical = 0, sumHorizontal = 0;
		tie(i, j) = p;
		i += inc, j += inc;
		
		ll len1 = sumOfY[i].size();
		ll len2 = sumOfX[j].size();
		
		if(len1 == 1|| len2 == 1) continue;
		
		ll idx1 = lb(yAtXEquals[i].begin(), yAtXEquals[i].end(), j - inc) - yAtXEquals[i].begin();
		ll idx2 = lb(xAtYEquals[j].begin(), xAtYEquals[j].end(), i - inc) - xAtYEquals[j].begin();

		assert(idx1 < len1);
		assert(idx2 < len2);
		
		sumVertical = sumOfY[i].back() - sumOfY[i][idx1];
		if(idx1) sumVertical -= sumOfY[i][idx1 - 1];
		sumVertical -= yAtXEquals[i][idx1]*(len1 - 1 - 2 * idx1);
		
		sumHorizontal = sumOfX[j].back() - sumOfX[j][idx2];
		if(idx2) sumHorizontal -= sumOfX[j][idx2 - 1]; 
		sumHorizontal -= xAtYEquals[j][idx2]*(len2 - 1 - 2 * idx2);
		
		ans += (sumVertical % MOD * sumHorizontal % MOD) % MOD;
		ans %= MOD;
	}
	
	cout << ans << '\n';
	
	return 0;
}

