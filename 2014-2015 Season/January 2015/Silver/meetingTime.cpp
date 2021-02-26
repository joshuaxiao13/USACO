#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define f first
#define s second

using ll = long long;
using vi = vector<int>;

vector<pair<int,int>> adjBessie[100], adjElsie[100];
bool dpBessie[100][10001], dpElsie[100][10001];


int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("meeting.in");
	ofstream cout ("meeting.out");
	
	int N, M;
	cin >> N >> M;
	
	while(M--) {
		int u, v, b, e;
		cin >> u >> v >> b >> e, --u, --v;
		adjBessie[u].eb(v, b);
		adjElsie[u].eb(v, e);
	}
	
	dpBessie[0][0] = dpElsie[0][0] = true;
	
	for(int i = 0; i < N - 1; ++i) {
		for(int t = 0; t <= 10000; ++t) {
			if(dpBessie[i][t]) {
				for(auto [j, w] : adjBessie[i]) {
					dpBessie[j][t+w] = true;
				}
			}
			if(dpElsie[i][t]){
				for(auto [j, w] : adjElsie[i]) {
					dpElsie[j][t+w] = true;
				}
			}
		}
	}
	
	int ans = -1;
	for(int t = 0; t <= 10000; ++t) {
		if(dpBessie[N-1][t] && dpElsie[N-1][t]) {
			ans = t;
			break;
		}
	}
	
	if(ans == -1) cout << "IMPOSSIBLE\n";
	else cout << ans << '\n';
	
	return 0;
}
