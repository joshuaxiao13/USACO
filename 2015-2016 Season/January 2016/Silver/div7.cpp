#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define f first
#define s second

using ll = long long;
using vi = vector<int>;

const int mxN = 5e4;

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("div7.in");
	ofstream cout ("div7.out");
	
	int N;
	cin >> N;
	
	vector<ll> ID(N);
	for(ll&x : ID)
		cin >> x;
		
	vector<int> MOD(7, -1);
	MOD[0] = 0;
	
	ll sum = 0;
	int ans = 0;
	
	for(int i = 0; i < N; ++i) {
		(sum += ID[i]) %= 7;
		if(MOD[sum] != -1)
			ans = max(ans, i + 1 - MOD[sum]);
		else
			MOD[sum] = i + 1;
	}
	
	cout << ans << '\n';
	
	return 0;
}
