#include <bits/stdc++.h>
using namespace std;

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int odd = 0, even = 0;
	
	int N;
	cin >> N;
	while(N--) {
		int x;
		cin >> x;
		if(x % 2 == 0) ++even;
		else ++odd;
	}
	
	int ans = 0;
	
	for(int i = 0; ; ++i) {
		if(i % 2 == 0) {
			if(even > 0) --even;
			else if(odd >= 2) odd -= 2;
			else break;
		}
		else {
			if(odd > 0) --odd;
			else break;
		}
		++ans;
	}
	
	// need to pair up an odd and even group, with the remaining odd that can't form an even
	if(odd % 2 == 1) --ans;
	
	cout << ans << '\n';
	
	return 0;
}
