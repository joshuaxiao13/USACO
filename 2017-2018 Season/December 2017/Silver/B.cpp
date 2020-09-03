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
	
	ifstream cin ("measurement.in");
	ofstream cout ("measurement.out");
	
	map<int,int> m;
	map<int,int> milked;
	int N, G;
	cin >> N >> G;
	vector<tuple<int,int,int>> recording(N);
	
	for(int i=0; i<N; ++i) {
		int day, id, delta;
		cin >> day >> id >> delta;
		recording[i] = make_tuple(day, id, delta);
	}
	
	sort(recording.begin(), recording.end());
	
	multiset<int> s;
	s.insert(0);	//will always be enough cows with output flow G
	
	m[get<1>(recording[0])]+=get<2>(recording[0]);
	s.insert(m[get<1>(recording[0])]);
	milked[get<1>(recording[0])]=1;
	int ans=1;
	
	for(int i=1; i<N; ++i) {
		int id=get<1>(recording[i]), delta=get<2>(recording[i]);
		
		if(milked[id]==0) s.insert(m[id]), milked[id]=1;
		int newOutput=m[id]+delta;
		int curOutput=m[id];
		int curMax=*--s.end();
		
		if(curOutput<curMax && newOutput>=curMax) ++ans;
		else if(curOutput==curMax) {
			if(newOutput>curMax && s.count(curOutput)>1) ++ans;
			else if(newOutput<curMax) {
				 if(s.count(curOutput)>1) ++ans;
				 else if(*s.lb(newOutput)!=curMax) ++ans;
			 }
		}
		
		auto it=s.lb(curOutput);
		s.erase(it);
		m[id]+=delta;
		s.insert(newOutput);
	}
	
	cout << ans << '\n';
	return 0;
}
