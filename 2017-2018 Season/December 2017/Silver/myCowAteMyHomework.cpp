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
	
	ifstream cin ("homework.in");
	ofstream cout ("homework.out");
	
	int n;
	cin >> n;
	vi score(n), sumFromBack(n,0), mn(n);
	vector<double> grade(n);
	for(int&q : score) cin >> q;
	
	sumFromBack[n-1]=score[n-1];
	mn[n-1]=score[n-1];
	
	double mxGrade=0;
	
	for(int i=n-2; i>=1; --i) {
		sumFromBack[i]=score[i];
		mn[i]=min(score[i], mn[i+1]);
		sumFromBack[i]+=sumFromBack[i+1];
		double curGrade = sumFromBack[i]-mn[i];
		curGrade/=(n-i-1);
		grade[i]=curGrade;
		mxGrade=max(mxGrade, curGrade);
	}
	
	vi ans;
	
	for(int i=1; i<=n-2; ++i)
		if(abs(grade[i]-mxGrade)<=1e-6)	ans.pb(i);
	
	for(int i=0; i<ans.size(); ++i) cout << ans[i] << '\n';
	
	return 0;
}
