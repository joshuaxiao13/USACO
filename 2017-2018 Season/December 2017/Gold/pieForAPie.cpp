// realized I don't really know how to binary search :(

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define f  first
#define s  second

using ll = long long;
using vi = vector<int>;

const int mxN = 1e5;

ll D;
int N, bestB[mxN], bestE[mxN];	// B for Bessie, E for Elsie

struct pie {
	ll tasteB, tasteE;
	int idx;
	pie(ll b, ll e, int i) :
 	tasteB(b), tasteE(e), idx(i) {}
};

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	ifstream cin ("piepie.in");
	ofstream cout ("piepie.out");

	cin >> N >> D;

	memset(bestB, -1, sizeof(bestB));
	memset(bestE, -1, sizeof(bestE));

	vector<pie> pieB, pieE;

	for(int i = 0; i < N; ++i) {
		ll tasteB, tasteE;
		cin >> tasteB >> tasteE;
		pie p(tasteB, tasteE, i);
		pieB.pb(p);
	}

	for(int i = 0; i < N; ++i) {
		ll tasteB, tasteE;
		cin >> tasteB >> tasteE;
		pie p(tasteB, tasteE, i);
		pieE.pb(p);
	}

	sort(pieB.begin(), pieB.end(), [&](pie x, pie y) {
		return x.tasteE < y.tasteE;
	});

	sort(pieE.begin(), pieE.end(), [&](pie x, pie y) {
		return x.tasteB < y.tasteB;
	});

	queue<pair<bool,int>> q;

	for(int i = 0; i < N; ++i) {
		if(pieB[i].tasteE == 0) {
			bestB[pieB[i].idx] = 1;
			q.push({true, i});
		}
	}

	for(int i = 0; i < N; ++i) {
		if(pieE[i].tasteB == 0) {
			bestE[pieE[i].idx] = 1;
			q.push({false, i});
		}
	}

	while(!q.empty()) {
		bool bessie;
		int id;
		tie(bessie, id) = q.front(); q.pop();

		if(bessie) {
			pie &p = pieB[id];
			int lhs = -1, rhs = -1;
			
			for(int k = N; k > 0; k /= 2) {
				while(rhs + k < N && p.tasteB - pieE[rhs+k].tasteB >= 0) {rhs += k;}
			}
			
			for(int k = N; k > 0; k /= 2) {
				while(lhs + k < N && p.tasteB - pieE[lhs+k].tasteB > D) {lhs += k;}
			}

			for(int j = lhs + 1; j <= rhs; ++j) {
				if(bestE[pieE[j].idx] != -1) continue;
				bestE[pieE[j].idx] = bestB[p.idx] + 1;
				q.push({false, j});
			}
		}

		else {
			pie &p = pieE[id];
			int lhs = -1, rhs = -1;

			for(int k = N; k > 0; k /= 2) {
				while(rhs + k < N && p.tasteE - pieB[rhs+k].tasteE >= 0) {rhs += k;}
			}

			for(int k = N; k > 0; k /= 2) {
				while(lhs + k < N && p.tasteE - pieB[lhs+k].tasteE > D) {lhs += k;}
			}

			for(int j = lhs + 1; j <= rhs; ++j) {
				if(bestB[pieB[j].idx] != -1) continue;
				bestB[pieB[j].idx] = bestE[p.idx] + 1;
				q.push({true, j});
			}
		}
	}

	for(int i = 0; i < N; ++i)
		cout << bestB[i] << '\n';

	return 0;
}	
