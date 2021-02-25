#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define f first
#define s second

using ll = long long;
using vi = vector<int>;

struct endpoint {
	int x, y, id;
	bool enter;
	bool operator< (const endpoint &p) {
		if(x == p.x) {
			if(enter && p.enter) return y < p.y;		// if two cows enter at the same time, we want to process the one with the least y-coordinate (the one infront)
			else if(!enter && !p.enter) return y > p.y;	// if two cows exit at the same time, we want to process the one with the greatest y-coordinate (the one behind)
			return enter;					// process a cow that enters before a cow that exits when two endpoints occur at the same time
		}
		return x < p.x;
	}
};

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("stampede.in");
	ofstream cout ("stampede.out");

	int N;
	cin >> N;
	
	// sweep line with endpoints representing the time each cow cross and exits line x = 0
	
	vector<endpoint> sweep;
	
	for(int i = 0; i < N; ++i) {
		int x, y, r;
		cin >> x >> y >> r;
		x *= -1;
		endpoint L, R;
		L.x = (x - 1) * r;
		R.x = x * r;
		R.y = L.y = y;
		L.enter = true;
		R.enter = false;
		R.id = L.id = i;
		sweep.pb(L);
		sweep.pb(R);
	}
	
	sort(sweep.begin(), sweep.end());
	
	int ans = 0;
	set<pair<int,int>> s;
	vector<bool> spotted(N, false);		// spotted[id] stores whether cow with id has already been spotted by Farmer John 
	
	/*	There are 3 cases when a cow can be spotted by Farmer John:
	 
	  1) Cow segment crosses line x = 0, and has the least y-coordinate of all cow segments currently having some part on x = 0
	  2) Cow segment exits line x = 0, and has the least y-coordinate of all cow segments currently having some part on x = 0
	  3) Cow segment gets spotted when a Cow segment exits. There are 2 ways to check this:
	  		a) let the Cow segment exit, then check whether the Cow segment with the least y-coordinate in the set has previously been marked
	   		b) before a new Cow segment crosses line x = 0, check if the Cow segment  with the least y-coordinate in the set has previously been marked
	  
	  	which ever way you decide, you can paste this block of code in the appropiate place:
	  
	  	if(!s.empty()) {
			int idx = (*s.rbegin()).s;
			if(!spotted[idx]) {
				++ans;
				spotted[idx] = true;
			}
		}
		
	 */
	
	for(int i = 0; i < 2*N; ++i) {
		endpoint &p = sweep[i];
		if(p.enter) {
			// paste here if you decide to go with choice a)
			s.insert({-p.y, p.id});
			if((*s.rbegin()).f == -p.y) {
				++ans;
				spotted[p.id] = true;
			}
		}
		else {
			if((*s.rbegin()).f == -p.y && !spotted[p.id])
				++ans;
			s.erase({-p.y, p.id});
			// delete the code below if you decide to go with choice a)
			if(!s.empty()) {
				int idx = (*s.rbegin()).s;
				if(!spotted[idx]) {
					++ans;
					spotted[idx] = true;
				}
			}
		}
	}
	
	cout << ans << '\n';
	
	return 0;
}
