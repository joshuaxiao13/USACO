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
	
	ofstream cout ("teleport.out");
	ifstream cin ("teleport.in");
 	
 	int a,b,from,to;
 	cin>>a>>b>>from>>to;
 	
 	int without = abs(b-a);
 	int with1 = abs(a-from)+abs(to-b);
 	int with2 = abs(a-to)+abs(from-b);
 	
 	cout<<min(without,min(with1,with2))<<"\n";;
	return 0;
}
