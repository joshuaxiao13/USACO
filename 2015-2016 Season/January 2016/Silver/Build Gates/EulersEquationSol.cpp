#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define eb emplace_back
#define f  first
#define s  second

using ll = long long;
using vi = vector<int>;

const int mxN = 2001;

int fence[mxN + 1][mxN + 1];

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	// https://www2.math.upenn.edu/~mlazar/math170/notes05-3.pdf
	// Euler's Eqution for Planar Graphs
	// V - E + F = 2
	// The minimum number of edges to connect F faces is F - 1 edges
	
	// F = E - V + 2
	// F - 1 = E - V + 1

	ifstream cin ("gates.in");
	ofstream cout ("gates.out");

	int N;
	string s;

	cin >> N >> s;
	
	int E = 0, V = 1;
	int curY = 1000, curX = 1000;
	int prevY, prevX;

	set<pair<int,int>> st;

	fence[curY][curX] = V;

	for(int i = 0; i < N; ++i) {
		prevY = curY;
		prevX = curX;
		if(s[i] == 'N') ++curY;
		else if(s[i] == 'E') ++curX;
		else if(s[i] == 'S') --curY;
		else --curX;
		if(fence[curY][curX] == 0) {
			++V;
			fence[curY][curX] = V;
			++E;
			st.insert(make_pair(V, fence[prevY][prevX]));
		}
		else if(st.find(make_pair(fence[curY][curX], fence[prevY][prevX])) == st.end() && st.find(make_pair(fence[prevY][prevX], fence[curY][curX])) == st.end()) {
			++E;
			st.insert(make_pair(fence[curY][curX], fence[prevY][prevX]));
		}
	}

	cout << E - V + 1 << '\n';

	return 0;
}
