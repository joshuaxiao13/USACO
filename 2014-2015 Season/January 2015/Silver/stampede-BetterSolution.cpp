// credits: Mark Gordan (http://www.usaco.org/current/data/sol_stampede_silver.html)

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define f first
#define s second

using ll = long long;
using vi = vector<int>;

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("stampede.in");
	ofstream cout ("stampede.out");

	int N;
	cin >> N;
	
	// sweep line with endpoints representing the time each cow cross and exits line x = 0
	
	vector<pair<int,int>> sweep;
	
	for(int i = 0; i < N; ++i) {
		int x, y, r;
		cin >> x >> y >> r, x *= -1;
		sweep.eb((x-1)*r, y);
		sweep.eb(x*r, -y);
	}
	
	sort(sweep.begin(), sweep.end());
	
	set<int> spotted, active;
	
	for(int i = 0; i < 2*N; ++i) {
		int cur = sweep[i].f;
		while(i < 2*N && sweep[i].f == cur) {
			if(sweep[i].s < 0)
				active.erase(-sweep[i].s);
			else 
				active.insert(sweep[i].s);
			++i;
		}
		
		--i;
		
		if(!active.empty())
			spotted.insert(*active.begin());
	}
	
	cout << spotted.size() << '\n';
	return 0;
}
