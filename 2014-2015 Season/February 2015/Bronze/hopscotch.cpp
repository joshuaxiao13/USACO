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
	
	ofstream cout ("hopscotch.out");
	ifstream cin ("hopscotch.in");
 	
 	int x,y;
 	cin>>y>>x;
 	
 	vector<vector<char>> board(y, vector<char>(x));
 	
 	for(int i=0; i<y; i++) {
		for(int j=0; j<x; j++) {
			cin>>board[i][j];
		}
	}
 	
 	vector<vi> dp(y,vi(x,0));
 	dp[0][0]=1;
 	
 	for(int i=0; i<y; i++) {
		for(int j=0; j<x; j++) {
			if(board[i][j]=='R') {
				for(int r=0; r<i; r++) {
					for(int c=0; c<j; c++) {
						if(board[r][c]=='R') continue;
						else dp[i][j]+=dp[r][c];
					}
				}
			}
			else {
				for(int r=0; r<i; r++) {
					for(int c=0; c<j; c++) {
						if(board[r][c]=='B') continue;
						else dp[i][j]+=dp[r][c];
					}
				}
			}
		}
	}
 	
 	cout<<dp[y-1][x-1]<<"\n";
	return 0;
}

