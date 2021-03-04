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
	
	int N;
	cin >> N;
	
	vector<vi> g(N+1, vi(N+1)), cntR(N+1, vi(N+1, 0)), closeR(N+1, vi(N+1, 600));;
	vector<vector<bool>> hasR(N+1, vector<bool>(N+1, false));
	
	for(int j = 0; j < N; ++j) {
		for(int i = 0; i < N; ++i) {
			int a;
			cin >> a;
			if(a < 100) g[j][i] = 0;
			else if(a > 100) g[j][i] = 2;
			else g[j][i] = 1;
		}
	}
	
	for(int j = N - 1; j >= 0; --j) {
		for(int i = N - 1; i >= 0; --i) {
			if(g[j][i] == 0) continue;
			cntR[j][i] = cntR[j][i+1] + 1;
			if(g[j][i] == 1) {
				hasR[j][i] = true;
				closeR[j][i] = 1;
			}
			else if(hasR[j][i+1]) {
				hasR[j][i] = true;
				closeR[j][i] = closeR[j][i+1] + 1;
			}
		}
	}
	
	ll ans = 0;
	
	for(int j = N - 1; j >= 0; --j) {
		for(int i = N - 1; i >= 0; --i) {
			int mxX = 600, closest = 600;
			for(int y = j; y < N; ++y) {
				mxX = min(mxX, cntR[y][i]);
				closest = min(closest, closeR[y][i]);
				if(mxX < closest) continue;
				ans += mxX - closest + 1;
			}

		}
	}
	
	cout << ans << '\n';
	
	return 0;
}
