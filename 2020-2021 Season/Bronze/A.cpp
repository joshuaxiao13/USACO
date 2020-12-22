#include <bits/stdc++.h>
using namespace std;

int num[7];
 
int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	for(int i = 0; i < 7; ++i) {
		cin >> num[i];
	}
	
	sort(num, num + 7);
	
	int sumBC = num[6] - num[0], lhs = 1, rhs = 5;
	
	while(lhs < rhs) {
		if(num[lhs] + num[rhs] == sumBC) break;
		else if(num[lhs] + num[rhs] > sumBC) --rhs;
		else ++lhs;
	}
	
	cout << num[0] << " " << num[lhs] << " " << num[rhs] << '\n';
	return 0;
}
