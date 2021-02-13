#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define f first
#define s second

using ll = long long;
using vi = vector<int>;

const int mxN = 1e3;
int up[mxN][mxN], down[mxN][mxN];

// up[i][j] = number of points with coordinate (h, k) such that h <= x-coordinate of point j and k >= y-coordinate of point i
// down[i][j] = number of points with coordinate(h, k) such that h <= x-coordinate of point j and k < y-coordinate of point i

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("balancing.in");
	ofstream cout ("balancing.out");
	
	int n;
	cin >> n;
	
	vector<pair<int,int>> cow(n);
	
	for(auto &[x,y] : cow)
		cin >> x >> y;
		
	sort(cow.begin(), cow.end());
	
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			int cntUp = 0, cntDown = 0, k = j;
			// while loop takes care of the case when mutlipe cows share the same x-coordinate
			while(k < n && cow[k].f == cow[j].f) {
				(cow[k].s >= cow[i].s ? ++cntUp : ++cntDown);
				++k;
			}
			if(j - 1 >= 0) {
				cntUp += up[i][j-1];
				cntDown += down[i][j-1];
			}
			for(int t = j; t < k; ++t) {
				up[i][t] = cntUp;
				down[i][t] = cntDown;
			}
			j = k - 1;
		}
	}
	
	int ans = n;
	
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			int NE, NW, SE, SW;
			SW = down[i][j];
			NW = up[i][j];
			NE = up[i][n-1] - NW;
			SE = down[i][n-1] - SW;
			assert(SW + NW + NE + SE == n);
			ans = min(ans, max({SW, NW, NE, SE}));
		}
	}
	
	cout << ans << '\n';
	return 0;
}
