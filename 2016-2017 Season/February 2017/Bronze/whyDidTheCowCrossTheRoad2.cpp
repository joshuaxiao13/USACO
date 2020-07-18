#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
 
typedef long long ll;
typedef vector<int> vi;
typedef unsigned long ul;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef set<int> si;
typedef multiset<int> mi;
 
const ll INF = 1e18;
const int MOD = 1e9+7;
 
int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ofstream cout ("circlecross.out");
	ifstream cin ("circlecross.in");
	
	vector<vi> letters(26);
	int ans=0;
 	
 	for(int i=0; i<52; ++i) {
		char c;
		cin>>c;
		letters[c-'A'].pb(i);
	}

	for(int i=0; i<26; ++i) {
		for(int j=0; j<26; ++j) {
			if(i==j) continue;
			else if(min(letters[i][0],letters[i][1])<min(letters[j][0],letters[j][1]) && max(letters[i][0],letters[i][1])>min(letters[j][0],letters[j][1]) && max(letters[i][0],letters[i][1])<max(letters[j][0],letters[j][1]))
					++ans;
			}
		}
	}
 	
 	cout<<ans<<"\n";
	return 0;
}
