#include <bits/stdc++.h>
using namespace std;

int n, petals[101], preSum[101], ans = 0;
vector<int> here[1001];

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> petals[i];
		preSum[i] += petals[i];
		if(i > 1) preSum[i] += preSum[i-1];
		here[petals[i]].push_back(i);
	}
	
	ans = n;
	for(int range = 2; range <= n; ++range) {
		for(int i = range; i <= n; ++i) {
			int sum = preSum[i] - preSum[i-range];
			if(sum % range != 0) continue;
			int P = sum/range;
			auto it = lower_bound(here[P].begin(), here[P].end(), i - range + 1);
			if(it != here[P].end() && *it >= i - range && *it <= i) ++ans;
		}
	}
	
	cout << ans << '\n';
	return 0;
}
