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
	
	ifstream cin ("lifeguards.in");
	ofstream cout ("lifeguards.out");
	
	int n;
	cin >> n;
	priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> q;
	vi decrease(n,0);	//decrease[i] = decrease in time covered if ith guard is fired
	
	for(int i=0; i<n; ++i) {
		int a, b;
		cin >> a >> b;
		q.push(make_tuple(a, 0, i));
		q.push(make_tuple(b, 1, i));
	}
	
	set<int> s;
	int onDuty=0, totalCovered=0, prev;
	
	while(!q.empty()) {
		int t, state, num;
		tie(t, state, num) = q.top();
		q.pop();
		
		if(state==0) {
			if(onDuty==0) prev=t;
			else if(onDuty==1) decrease[*s.begin()]+=t-prev;
			totalCovered+=t-prev;
			prev=t;
			s.insert(num);
			++onDuty;
		}
		
		else {
			if(onDuty==1) decrease[*s.begin()]+=t-prev;
			totalCovered+=t-prev;
			prev=t;
			s.erase(s.lb(num));
			--onDuty;
		}
	}
	
	int minDecrease=INT_MAX;
	for(auto x: decrease) minDecrease=min(x, minDecrease);
	
	cout << totalCovered-minDecrease << '\n';
	return 0;
}
