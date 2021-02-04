#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define f first
#define s second

using ll = long long;
using vi = vector<int>;

int grid[1000][1000];
int N;

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> N;
	
	for(int j = 0; j < N; ++j) {
		for(int i = 0; i < N; ++i) {
			cin >> grid[j][i];
		}
	}
	
	// case 1: alternate horizontal
	
	int ans1 = 0, ans2 = 0;
	
	for(int j = 0; j < N; ++j) {
		int sum1 = 0, sum2 = 0;
		for(int i = 0; i < N; ++i) {
			if(i % 2 == 0) sum1 += grid[j][i];
			else sum2 += grid[j][i];
		}
		ans1 += max(sum1, sum2);
	}
	
	// case 2: alternate vertical
	
	for(int i = 0; i < N; ++i) {
		int sum1 = 0, sum2 = 0;
		for(int j = 0; j < N; ++j) {
			if(j % 2 == 0) sum1 += grid[j][i];
			else sum2 += grid[j][i];
		}
		ans2 += max(sum1, sum2);
	}
	
	cout << max(ans1, ans2) << '\n';
	
	return 0;
}
