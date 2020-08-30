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
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
 
const ll INF = 1e18;
const int MOD = 1e9+7;
 
int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("hps.in");
	ofstream cout ("hps.out");
	
	int n;
	cin >> n;
	
	vector<vi> plays(n, vi(3,0));	//0=H, 1=S, 2=P
	
	for(int i=0; i<n; ++i) {
		char move;
		cin >> move;
		
		if(move=='H') ++plays[i][0];
		else if(move=='S') ++plays[i][1];
		else ++plays[i][2];
		
		if(i>0) {
			for(int j=0; j<3; ++j) plays[i][j]+=plays[i-1][j];
		}
	}
	
	int ans=0;
	
	for(int i=0; i<n-1; ++i) {
		for(int p1=0; p1<3; ++p1) {
			for(int p2=0; p2<3; ++p2) {
				if(p1==p2) continue;
				
				int temp=0;
				temp+=plays[i][(p1+1)%3];
				temp+=plays[n-1][(p2+1)%3]-plays[i][(p2+1)%3];
				ans = max(ans, temp);
			}
		}
	}
	
	for(int i=0; i<3; ++i) ans=max(ans, plays[n-1][(i+1)%3]);
	
	cout << ans << '\n';
	return 0;
}
