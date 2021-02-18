#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define f first
#define s second

using ll = long long;
using vi = vector<int>;

const int mxN = 5e4;

int N, K;
int cow[mxN];

bool valid(int R) {
	int cnt = 0;
	for(int i = 0; i < N && cnt <= K; ++i) {
		++cnt;
		int idx = i;
		for(int j = N; j > 0; j/=2) {
			while(idx + j < N && cow[idx + j] <= cow[i] + 2*R) {
				idx += j;
			}
		}
		i = idx;
	}
	return cnt <= K;
}

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("angry.in");
	ofstream cout ("angry.out");
	
	cin >> N >> K;
	
	for(int i = 0; i < N; ++i) {
		cin >> cow[i];
	}
	
	sort(cow, cow + N);
	
	int ans = 0;
	for(int j = 1000000000; j > 0; j/=2) {
		while(ans + j <= 1000000000 && !valid(ans + j)) {
			ans += j;
		}
	}
	
	++ans;
	
	cout << ans << '\n';
	
	return 0;
}
