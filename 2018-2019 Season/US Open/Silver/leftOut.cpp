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
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> indexed_set;
 
const ll INF = 1e18;
const int MOD = 1e9+7;

int N;
bool g[10001][10001];

int countUp(int r1, int r2, int c1, int c2, bool good) {
	
	int cnt = 0;
	
	for(int j = r1; j <= r2; ++j) {
		for(int i = c1; i <= c2; ++i) {
			if(g[j][i] == good) ++cnt;
		}
	}
	
	return cnt;
}

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("leftout.in");
	ofstream cout ("leftout.out");
	
	cin >> N;
	
	for(int j = 0; j < N; ++j) {
		string row;
		cin >> row;
		for(int i = 0; i < N; ++i) {
			g[j][i] = (row[i] == 'R' ? true : false);
		}
	}
	
	//flip to make left column all 0
	for(int j = 0; j < N; ++j) {
		if(g[j][0]) {
			for(int i = 0; i < N; ++i) g[j][i] = !g[j][i];
		}
	}
	
	//flip to make top row all 0
	for(int i = 0; i < N; ++i) {
		if(g[0][i]) {
			for(int j = 0; j < N; ++j) g[j][i] = !g[j][i];
		}
	}
	
	int temp = countUp(1, N - 1, 1, N - 1, true);
	
	//everything is one direction, no solution
	if(temp == 0) cout << "-1\n";
	
	//every element except top row and left column is 1, simply flip top row and left column and switch the element in the top-left corner
	else if(temp == (N - 1)*(N - 1)) cout << "1 1\n";
	
	//if a row or column begins with a zero and ends with all 1s, flip that row/column and switch the first element in that row/column
	else if(temp == N - 1) {
		
		for(int i = 1; i < N; ++i) {
			if(g[1][i]) {
				cout << "1 " << i + 1 << '\n';
				return 0;
			}
		}
		
		for(int j = 1; j < N; ++j) {
			if(g[j][1]) {
				cout << j + 1 << " 1\n";
				return 0;
			}
		}
		
		cout << "-1\n";
	}
	
	//switch the distinct element
	else if(temp == 1) {
		for(int j = 1; j < N; ++j) {
			for(int i = 1; i < N; ++i) {
				if(g[j][i]) {
					cout << j + 1 << " " << i + 1 << '\n';
					return 0;
				}
			}
		}
	}
	
	//not possible
	else cout << "-1\n";
	
	return 0;
}
