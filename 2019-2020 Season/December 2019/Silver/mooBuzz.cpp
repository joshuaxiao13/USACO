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

bool valid(int x) {

	return x%3 && x%5;
}
 
int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("moobuzz.in");
	ofstream cout ("moobuzz.out");

	int N;
	cin >> N;
		
	vi v = {0};
	for(int i = 1; i <= 15; ++i) if(valid(i)) v.pb(i);
		
	int temp = (N - 1)/8;
		
	cout << v[N - temp*8] + 15*temp << '\n';
	
	return 0;
}

