#include <bits/stdc++.h>
using namespace std;

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	string alpha, phrase;
	
	cin >> alpha >> phrase;
	
	vector<int> pos(26);
  
	for(int i = 0; i < 26; ++i) {
		pos[alpha[i]-'a'] = i;
	}
	
	int cnt = 1, cur = -1;
	
	for(char c : phrase) {
		if(pos[c-'a'] <= cur) ++cnt;
		cur = pos[c-'a'];
	}
	
	cout << cnt << '\n';
	
	return 0;
}
