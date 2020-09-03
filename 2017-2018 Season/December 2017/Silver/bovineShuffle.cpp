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

int n, ans=0;
int adj[100001];
int color[100001];	//0-haven't visited or visiting, 1-processed

void colorIn(int x) {
	
	if(color[x]==1) return;
	color[x]=1;
	colorIn(adj[x]);
}

void floydsAlgo(int x) {
	
	int a=adj[x], b=adj[adj[b]];
	while(a!=b && color[a]!=1 && color[b]!=1) {
		a=adj[a];
		b=adj[adj[b]];
	}
	
	if(a==b && color[a]==0) {
		a=x;
		while(a!=b) {
			a=adj[a];
			b=adj[b];
		}
		
		a=adj[a];
		int length=1;
		while(a!=b) ++length, a=adj[a];
		ans+=length;
	}
	
	colorIn(x);
}
 
int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("shuffle.in");
	ofstream cout ("shuffle.out");
	
	cin >> n;
	
	for(int i=1; i<=n; ++i) cin >> adj[i];
	
	for(int i=1; i<=n; ++i) {
		if(color[i]) continue;
		else floydsAlgo(i);
	}
	
	cout << ans << '\n';
	return 0;
}
