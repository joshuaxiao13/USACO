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
    
    //ofstream cout ("cowjog.out");
    //ifstream cin ("cowjog.in");
    
    int n;
    cin>>n;
    vi v(n);
    
    for(int i=0; i<n; i++) {
        int a;
        cin>>a>>v[i];
    }
    
    int count=1, front=v.back();
    
    for(int i=n-2; i>=0; i--) {
        if(v[i]>front) continue;
        else count++, front=v[i];
    }
    
    cout<<count<<"\n";
    return 0;
}
