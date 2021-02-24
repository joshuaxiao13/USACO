#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define f first
#define s second

using ll = long long;
using vi = vector<int>;

int N, ID[2000], mxW[2000];
bool used[2000];

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("superbull.in");
	ofstream cout ("superbull.out");
	
	cin >> N;
	
	for(int i = 0; i < N; ++i) {
		cin >> ID[i];
	}
	
	ll ans = 0;
	
	for(int i = 0; i < N; ++i) {
		int u = -1;
		for(int v = 0; v < N; ++v) {
			if(!used[v] && (u == -1 || mxW[v] > mxW[u])) {
				u = v;
			}
		}
		ans += mxW[u];
		used[u] = true;
		for(int v = 0; v < N; ++v) {
			mxW[v] = max(mxW[v], ID[u] ^ ID[v]);
		}
	}
	
	cout << ans << '\n';
	
	return 0;
}
