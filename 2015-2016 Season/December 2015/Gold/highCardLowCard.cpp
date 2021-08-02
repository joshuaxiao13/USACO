#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("cardgame.in");
	ofstream cout ("cardgame.out");
	
	int N; cin >> N;
	
	vector<bool> vis(2*N + 1, false);
	vector<int> elsie(N);
	
	for (int& x : elsie) {
		cin >> x;
		vis[x] = true;
	}
	
	set<int> half1, half2;
	
	for (int i = 1; i <= 2*N; ++i) {
		if (vis[i]) continue;
		half2.size() < N/2 ? half2.insert(i) : half1.insert(i);
	}
	
	int ans = 0;
	
	for (int i = 0; i < N/2; ++i) {
		auto it = half1.upper_bound(elsie[i]);
		if (it == half1.end()) it = half1.begin();
		else ++ans;
    half1.erase(it);
	}
	
	for (int i = N/2; i < N; ++i) {
		auto it = half2.upper_bound(elsie[i]);
		if (it == half2.begin()) it = half2.end();
		else ++ans;
		advance(it, -1);
		half2.erase(it);
	}
	
	cout << ans << '\n';

	return 0;
}
