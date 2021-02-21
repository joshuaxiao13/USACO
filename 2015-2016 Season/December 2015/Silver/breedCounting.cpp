#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define f first
#define s second

using ll = long long;
using vi = vector<int>;

const int mxN = 1e5;
int breed[3][mxN + 1];

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("bcount.in");
	ofstream cout ("bcount.out");
	
	int N, Q;
	cin >> N >> Q;
	
	// solve with prefix sums
	
	for(int i = 1; i <= N; ++i) {
		int x;
		cin >> x, --x;
		++breed[x][i];
		for(int j = 0; j < 3; ++j)
			breed[j][i] += breed[j][i-1];
	}
	
	while(Q--) {
		int a, b;
		cin >> a >> b;
		for(int i = 0; i < 3; ++i)
			cout << breed[i][b] - breed[i][a-1] << (i == 2 ? "\n" : " ");
	}
	
	return 0;
}
