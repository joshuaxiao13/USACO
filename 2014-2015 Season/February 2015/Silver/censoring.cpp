// rolling hash

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define f first
#define s second

using ll = long long;
using vi = vector<int>;

const ll P = 9973, M = 1e9 + 9;

ll p[1000001];
vector<ll> hsh;
string s, t, ans = "";
int n, m;

void compute_powers() {
	p[0] = 1;
	for(int i = 1; i <= m; ++i)			// we only need up to p[m-1] to calculate the hash of string t, but since we require p[m] in get_hash(),
		p[i] = (p[i-1] * P) % M;		// which returns the hash value of the current suffix of of size m for string ans, we calculate p[m]
}

ll get_hash() {
	int sz = ans.size();
	if(sz == m) return hsh[sz - 1];
	return (hsh[sz - 1] - (hsh[sz - m - 1] * p[m]) % M + M) % M;
}

int main() {
    
   	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("censor.in");
	ofstream cout ("censor.out");
	
	cin >> s >> t;
	
	n = s.size();
	m = t.size();
	
	compute_powers();
	
	ll hashT = 0;		// stores hash of string t
	
	for(int i = 0; i < m; ++i) {
		(hashT += (t[i] * p[m - 1 - i]) % M) %= M;
	}
	
	for(int i = 0; i < n; ++i) {
		ans += s[i];
		ll cur = (hsh.empty() ? 0 : hsh.back());
		cur = ((cur * P) % M + s[i]) % M;
		hsh.pb(cur);
		if(ans.size() >= m && get_hash() == hashT) {
			ans.resize(ans.size() - m);
			hsh.resize(hsh.size() - m);
		}
	}
	
	cout << ans << '\n';
	
    	return 0;
}
