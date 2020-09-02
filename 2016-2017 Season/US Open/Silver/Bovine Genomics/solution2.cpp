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

int n, m;
int spot[500][50], plain[500][50];
bool a[64];

bool valid(int i, int j, int k) {
	
	bool good=true;
	
	for(int w=0; w<n; ++w) {
		int temp=16*spot[w][i]+4*spot[w][j]+spot[w][k];
		a[temp]=true;
	}
	
	for(int w=0; w<n; ++w) {
		int temp=16*plain[w][i]+4*plain[w][j]+plain[w][k];
		if(a[temp]) {
			good=false;
			break;
		}
	}
	
	for(int w=0; w<n; ++w) {
		int temp=16*spot[w][i]+4*spot[w][j]+spot[w][k];
		a[temp]=false;
	}

	return good;
}
 
int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("cownomics.in");
	ofstream cout ("cownomics.out");
	
	map<char,int> M;
	M['A']=0;
	M['C']=1;
	M['G']=2;
	M['T']=3;
	
	cin >> n >> m;
	
	for(int j=0; j<n; ++j) {
		string s;
		cin >> s;
		for(int i=0; i<m; ++i) {
			spot[j][i]=M[s[i]];
		}
	}
	
	for(int j=0; j<n; ++j) {
		string s;
		cin >> s;
		for(int i=0; i<m; ++i) {
			plain[j][i]=M[s[i]];
		}
	}
	
	int ans=0;
	
	for(int i=0; i<m; ++i)
		for(int j=i+1; j<m; ++j)
			for(int k=j+1; k<m; ++k)
				if(valid(i, j, k)) ++ans;

	cout << ans << '\n';
	return 0;
}
