#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define f first
#define s second

using ll = long long;
using vi = vector<int>;

unordered_set<int> letter[26][7];

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("bgm.in");
	ofstream cout ("bgm.out");
	
	int N;
	cin >> N;
	
	while(N--) {
		char c;
		int num;
		cin >> c >> num;
		int x = num % 7;
		if(x < 0) x += 7;
		letter[c - 'A'][x].insert(num);
	}
	
  // if (B + E + S + S + I + E) (G + O + E + S) (M + O + O) is a
  // a multiple of 7, one of the "parts" must be a multiple of 7
  // this is because 7 is a prime number, we are only concerned with
  // the the variables modulo 7, we can run through all 7^7 possibilites
  
	ll ans = 0;
	
	for(int B = 0; B < 7; ++B) {
		ll b = letter['B'-'A'][B].size();
		if(b == 0) continue;
		for(int E = 0; E < 7; ++E) {
			ll e = letter['E'-'A'][E].size();
			if(e == 0) continue;
			for(int S = 0; S < 7; ++S) {
				ll s = letter['S'-'A'][S].size();
				if(s == 0) continue;
				for(int I = 0; I < 7; ++I) {
					ll i = letter['I'-'A'][I].size();
					if(i == 0) continue;
					for(int G = 0; G < 7; ++G) {
						ll g = letter['G'-'A'][G].size();
						if(g == 0) continue;
						for(int O = 0; O < 7; ++O) {
							ll o = letter['O'-'A'][O].size();
							if(o == 0) continue;
							for(int M = 0; M < 7; ++M) {
								ll m = letter['M'-'A'][M].size();
								if(m == 0) continue;
								int mod1 = (B + E + S + S + I + E) % 7;
								int mod2 = (G + O + E + S) % 7;
								int mod3 = (M + O + O) % 7;
								if(mod1 == 0 || mod2 == 0 || mod3 == 0) {
									ans += b * e * s * i * g * o * m;
								}
							}
						}
					}
				}
			}
		}
	}
	
	assert(ans >= 0);
	cout << ans << '\n';
	
	return 0;
}
