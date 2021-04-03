#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define eb emplace_back
#define f  first
#define s  second

using ll = long long;
using vi = vector<int>;

int main() { 
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	ifstream cin ("hayfeast.in");
	ofstream cout ("hayfeast.out");

	int N; cin >> N;
	ll M; cin >> M;
	vector<pair<int,int>> bale(N);
	for(auto &[flav, spice] : bale) cin >> flav >> spice;

	multiset<int> ms;
	ll sum = 0;
	int lhs = 0, ans = INT_MAX;

	for(int rhs = 0; rhs < N; ++rhs) {
		sum += bale[rhs].f;
		ms.insert(bale[rhs].s);
		while(sum - bale[lhs].f >= M) {
			sum -= bale[lhs].f;
			ms.erase(ms.find(bale[lhs].s));
			++lhs;
		}
		if(sum >= M) ans = min(ans, *ms.rbegin());
	}

	cout << ans << '\n';
	return 0;
}

/*
* use long long when dealing with MOD 1e9 + 7
* clear memory after testcases
*/

