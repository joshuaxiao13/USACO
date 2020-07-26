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
typedef unsigned long ul;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef set<int> si;
typedef multiset<int> mi;
 
const ll INF = 1e18;
const int MOD = 1e9+7;
 
int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	ofstream cout ("herding.out");
	ifstream cin ("herding.in");
 	
 	int a,b,c;
 	cin>>a>>b>>c;
 	int total=a+b+c;
 	int mx = max({a,b,c});
 	int mn = min({a,b,c});
 	int mid=total-mx-mn;
 	
	int gap1=mx-mid-1;
	int gap2=mid-mn-1;
	
	if(mn==mid-1 && mx==mid+1) cout<<"0\n";
	else if(gap1==1 || gap2==1) cout<<"1\n";
	else cout<<"2\n";
 	cout<<max(gap1,gap2)<<"\n";
 	
	return 0;
}
