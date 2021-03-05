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
	
	for(int i = 0; i < N; ++i) {
		int years;
		cin >> years;
		int left = (years/12);
		int right = left + 1;
		s.insert({left, right});
	}
	
	int ans = 12*(*s.rbegin()).s;
	
	vi gap;
	int prev = 0;
	while(!s.empty()) {
		gap.pb((*s.begin()).f - prev);
		prev = (*s.begin()).s;
		s.erase(s.begin());
	}
	
	sort(gap.rbegin(), gap.rend());
	
	for(int i = 0; i < N - 1 && K > 1; ++i){
		ans -= gap[i]*12;
		--K;
	}
	
	cout << ans << '\n';
	
	return 0;
}
