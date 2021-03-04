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
	
	int N, K;
	cin >> N >> K;
	
	set<pair<int,int>> s;
	vector<pair<int,int>> interval;
	
	for(int i = 0; i < N; ++i) {
		int years;
		cin >> years;
		int left = (years/12);
		int right = left + 1;
		if(s.count(make_pair(left, right)) == 0) {
			interval.eb(left, right);
			s.insert({left, right});
		}
	}
	
	sort(interval.begin(), interval.end());
	int n = interval.size();
	int ans = 12*interval[n-1].s;
	
	vi gap;
	gap.pb(interval[0].f);
	for(int i = 1; i < n; ++i) {
		gap.pb(interval[i].f - interval[i-1].s);
	}
	
	sort(gap.rbegin(), gap.rend());
	
	for(int i = 0; i < gap.size() && K > 1; ++i){
		ans -= gap[i]*12;
		--K;
	}
	
	cout << ans << '\n';
	
	return 0;
}
