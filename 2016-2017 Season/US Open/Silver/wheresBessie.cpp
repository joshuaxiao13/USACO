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
 
int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("where.in");
	ofstream cout ("where.out");
	
	int n;
	cin >> n;
	
	vector<vector<char>> v(n, vector<char>(n));
	
	for(int j=0; j<n; ++j) {
		string row;
		cin >> row;
		for(int i=0; i<n; ++i) v[j][i]=row[i];
	}
	
	vector<pair<pi,pi>> coords;		//stores the max and min x- and y-coordinates of each potential cow location (PCL)
	int ans=0;
	
	for(int s1=n; s1>=1; --s1) {
		for(int s2=n; s2>=1; --s2) {
			if(s1*s2<3) continue;		//not sufficient enough for at least 3 contingous regions
			for(int j=0; j+s1-1<n; ++j) {
				for(int i=0; i+s2-1<n; ++i) {
					
					//check if current rect is a subset of a previous one
					bool notSubset=true;
					for(int w=0; w<coords.size() && notSubset; ++w) {
						pair<pi,pi> &p=coords[w];
						if(j>=p.f.f && j+s1-1<=p.f.s && i>=p.s.f && i+s2-1<=p.s.s) notSubset=false;
					}
					
					if(!notSubset) continue;
					
					//check if there exists exactly 2 distinct characters in rect
					set<char> s;
					bool good=true;
					
					for(int r=j; r<j+s1 && good; ++r) {
						for(int c=i; c<i+s2 && good; ++c) {
							s.insert(v[r][c]);
							if(s.size()>2) good=false;
						}
					}
					
					if(s.size()!=2) continue;
					else {
						char c1=*s.begin();
						int cnt1=0, cnt2=0;		//counters for the number of contingous regions belong to each character
						
						vector<vector<bool>> visited(n, vector<bool>(n,false));
						queue<pi> q;
						bool oneContingous=true;
						
						//transverse the squares of rect
						for(int r=j; r<j+s1 && oneContingous; ++r) {
							for(int c=i; c<i+s2 && oneContingous; ++c) {
								
								//perform bfs to count number of contigous regions for each character
								if(!visited[r][c]) {
									if(v[r][c]==c1) ++cnt1;
									else ++cnt2;
									visited[r][c]=true;
									q.push({r,c});
									
									while(!q.empty()) {
										
										int y=q.front().f, x=q.front().s;
										q.pop();
										
										if(y-1>=j && !visited[y-1][x] && v[y][x]==v[y-1][x]) q.push({y-1,x}), visited[y-1][x]=true;
										if(y+1<j+s1 && !visited[y+1][x] && v[y][x]==v[y+1][x]) q.push({y+1,x}), visited[y+1][x]=true;
										if(x-1>=i && !visited[y][x-1] && v[y][x]==v[y][x-1]) q.push({y,x-1}), visited[y][x-1]=true;
										if(x+1<i+s2 && !visited[y][x+1] && v[y][x]==v[y][x+1]) q.push({y,x+1}), visited[y][x+1]=true;
										
									}
								}
								//if each character has more than one contingous region
								if(cnt1>=2 && cnt2>=2) oneContingous=false;
							}
						}
						
						if(!oneContingous) continue;
						else if(cnt1==1 && cnt2>=2 || cnt2==1 && cnt1>=2) {		//boolean oneContingous doesn't gurantee requirments Ex. doesn't catch cnt1=1, cnt2=1 (which doesn't satsify requirements)
							++ans;
							coords.pb({{j, j+s1-1},{i, i+s2-1}});
						}
					}
				}
			} 
		}
	}
	
	cout << ans << '\n';
	return 0;
}
