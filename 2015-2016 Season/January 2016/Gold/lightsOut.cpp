#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("lightsout.in");
	ofstream cout ("lightsout.out");
	
	int N; cin >> N;
	
	pair<int,int> p[N];
	int best[N];
	vector<int> angle[2];
	
	for (auto& [x, y] : p) cin >> x >> y;
	
	int perimeter = 0;
	
	auto edgeLength = [&](int x) {
		auto &a = p[x];
		auto &b = p[(x-1+N)%N];
		return abs(a.first - b.first) + abs(a.second - b.second);
	};
	
	auto rightAngle = [&](int x) {
		auto& a = p[(x-1+N)%N];
		auto& b = p[x];
		auto& c = p[(x+1)%N];
		if (a.first == b.first) return (b.second < a.second) == (b.first > c.first);
		return (b.first < a.first) == (b.second < c.second);
	};
		
	for (int i = 0; i < N; ++i) {
		angle[rightAngle(i)].push_back(i);
		perimeter += edgeLength(i);
	}

	best[0] = 0;
	int cur = 0;
	
	for (int i = 1; i < N; ++i) {
		cur += edgeLength(i);
		best[i] = min(cur, perimeter - cur);
	}
	
	int ans = 0;
	
	for (int i = 1; i < N; ++i) {
		queue<tuple<int,int,int>> q;
		for (auto x : angle[rightAngle(i)]) {
			if (x == i) continue;
			q.push(make_tuple(edgeLength((i+1)%N), (x+1)%N, (i+1)%N));
		}
		int pos = i;
		int D = 0;
		while (!q.empty()) {
			int d, u, v;
			tie (d, u, v) = q.front(); q.pop();
			D = max(D, d);
			pos = max(pos, v);
			if (v == 0) {
				pos = 0;
				break;
			}
			if (u == 0 || edgeLength(u) != edgeLength(v) || rightAngle(u) != rightAngle(v)) continue;
			q.push(make_tuple(d + edgeLength((v+1)%N), (u+1)%N, (v+1)%N));
		}
 		ans = max(ans, D + best[pos] - best[i]);
	}

	cout << ans << '\n';
	
	return 0;
}
