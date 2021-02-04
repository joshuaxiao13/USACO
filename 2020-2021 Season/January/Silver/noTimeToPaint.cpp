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
	
	int N, Q;
	string fence;
	cin >> N >> Q >> fence;
	
	vi psumForward(N, 0), psumBackward(N, 0);
	
	for(int ch = 0; ch < 26; ++ch) {
		char c = ('A' + ch);
		bool newStroke = true;
		for(int i = 0; i < N; ++i) {
			if(fence[i] == c) {
				if(newStroke) {
					++psumForward[i];
					newStroke = false;
				}
			}
			else if(!newStroke && fence[i] < c) {
				newStroke = true;
			}
		}
	}
	
	for(int ch = 0; ch < 26; ++ch) {
		char c = ('A' + ch);
		bool newStroke = true;
		for(int i = N - 1; i >= 0; --i) {
			if(fence[i] == c) {
				if(newStroke) {
					++psumBackward[i];
					newStroke = false;
				}
			}
			else if(!newStroke && fence[i] < c) {
				newStroke = true;
			}
		}
	}
	
	for(int i = 1; i < N; ++i)
		psumForward[i] += psumForward[i-1];
		
	for(int i = N - 2; i >= 0; --i)
		psumBackward[i] += psumBackward[i+1];
		
	while(Q--) {
		int a, b;
		cin >> a >> b, --a, -- b;
		cout << (a - 1 == -1 ? 0 : psumForward[a-1]) + (b + 1 == N ? 0 : psumBackward[b+1]) << '\n';
	}
	
	return 0;
}
