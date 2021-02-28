#include <bits/stdc++.h>
using namespace std;

int N, a[20], b[20];

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	
	for(int i = 0; i < N; ++i)
		cin >> a[i];
	
	for(int i = 0; i < N; ++i)
		cin >> b[i];
	
	sort(a, a + N, greater<int>());
	sort(b, b + N, greater<int>());

	long long ans = 1;
	int bound = -1;

	for(int i = 0; i < N; ++i) {
		while(bound + 1 < N && b[bound + 1] >= a[i])
			++bound;
		if(bound + 1 - i <= 0) {
			cout << "0\n";
			break;
		}
		ans *= bound + 1 - i;
	}
	
	cout << ans << '\n';
	
	return 0;
}
