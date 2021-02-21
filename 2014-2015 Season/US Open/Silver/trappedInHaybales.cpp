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
	
	ifstream cin ("trapped.in");
	ofstream cout ("trapped.out");
	
	int N, B;
	cin >> N >> B;
	
	vector<pair<int,int>> bale(N);
	for(auto &[P,S] : bale)
		cin >> S >> P;
	
	sort(bale.begin(), bale.end());
	
	int M = lower_bound(bale.begin(), bale.end(), make_pair(B, 0)) - bale.begin();
	
	// fix the bale (to the right of the starting position) we will increase
	// keep breaking through bales towards the left and update answer once an unbreakable left bale appears
	
	int ans = INT_MAX;
	
	int j = M - 1;
	for(int i = M; i < N; ++i) {
		while(j >= 0 && bale[i].f - bale[j].f > bale[j].s)
			--j;
		if(j >= 0) ans = min(ans, max(0, bale[i].f - bale[j].f - bale[i].s));
	}
	
	// fix the bale (to the right of the starting position) we will increase
	// keep breaking through bales towards the right and update answer once an unbreakable right bale appears
	
	j = M;
	for(int i = M - 1; i >= 0; --i) {
		while(j < N && bale[j].f - bale[i].f > bale[j].s)
			++j;
		if(j < N) ans = min(ans, max(0, bale[j].f - bale[i].f - bale[i].s));
	}
	
	cout << (ans != INT_MAX ? ans : -1) << '\n';
	
	return 0;
}
