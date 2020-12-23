#include <bits/stdc++.h>
using namespace std;

int num[7];
 
int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	for(int i = 0; i < 7; ++i)
		cin >> num[i];
	
	sort(num, num + 7);
	
	int A = num[0], B = num[1], C = num[6] - A - B;
	
	cout << A << " " << B << " " << C << '\n';
	return 0;
}
