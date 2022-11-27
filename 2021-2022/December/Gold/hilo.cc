#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	int N; cin >> N;
	
	vector<int> psum(N+2, 0);
	vector<int> idx(N+2, 0);
	set<int> s;

	for (int i = 1; i <= N; ++i) {
		int size; cin >> size;
		idx[size] = i;
		set<int>::iterator it = s.upper_bound(size);
		int ub = (it == s.end() ? N+1 : *it);
		int lb = (it == s.begin() ? 0 : *(--it));
		if (idx[ub] > idx[lb]) {
			++psum[size];
			--psum[ub];
		}
		s.insert(size);
	}

	for (int i = 1; i <= N; ++i) psum[i] += psum[i-1];
	for (int i = 0; i <= N; ++i) cout << psum[i] << '\n';
}
