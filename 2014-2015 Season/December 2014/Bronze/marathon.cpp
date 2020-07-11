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
    
    //ofstream cout ("marathon.out");
    //ifstream cin ("marathon.in");
    
    int n,prevA,prevB,total=0;
    cin>>n;
    vpi v(n);
    
    cin>>prevA>>prevB;
    v[0]={prevA,prevB};
    
    for(int i=1; i<n; i++) {
        int a,b;
        cin>>a>>b;
        v[i]={a,b};
        total+=abs(a-prevA)+abs(b-prevB);
        prevA=a;
        prevB=b;
    }
    
    int best=total;
    for(int i=1; i<n-1; i++) {
        int a,b,c,d,e,f;
        tie(a,b)=v[i-1];
        tie(c,d)=v[i];
        tie(e,f)=v[i+1];
        int temp=total-abs(c-a)-abs(d-b)-abs(c-e)-abs(d-f)+abs(a-e)+abs(b-f);
        best=min(best,temp);
    }
    
    cout<<best<<"\n";
    return 0;
}
