#include <bits/stdc++.h>
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
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //ofstream cout ("crosswords.out");
    //ifstream cin ("crosswords.in");
 
    int n,m;
    cin>>n>>m;
    vector<vector<char>> grid(n,vector<char>(m));
    vpi blocked;
    set<pi> v;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>grid[i][j];
            if(grid[i][j]=='#') blocked.pb({i,j});
        }
    }
    
    for(int i=0; i<n; i++) {
        if(grid[i][0]=='.' && grid[i][1]=='.' && grid[i][2]=='.')
            v.insert({i,0});
    }
    
    for(int i=0; i<m; i++) {
        if(grid[0][i]=='.' && grid[1][i]=='.' && grid[2][i]=='.')
            v.insert({0,i});
    }
    
    for(auto x: blocked) {
        if(x.s+3<m && grid[x.f][x.s+1]=='.' && grid[x.f][x.s+2]=='.' && grid[x.f][x.s+3]=='.')
            v.insert({x.f,x.s+1});
        if(x.f+3<n && grid[x.f+1][x.s]=='.' && grid[x.f+2][x.s]=='.' && grid[x.f+3][x.s]=='.')
            v.insert({x.f+1,x.s});
    }
    
    cout<<v.size()<<"\n";
    for(auto x: v)
        cout<<x.f+1<<" "<<x.s+1<<"\n";
    
    return 0;
}
