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
    
    ofstream cout ("learning.out");
    ifstream cin ("learning.in");
    
    int n,a,b;
    cin>>n>>a>>b;
    
    vector<pair<int,string>> cow(n);     //first element is weight, second is S/NS
    
    for(int i=0; i<n; i++) {
        string s;
        int w;
        cin>>s>>w;
        cow[i]={w,s};
    }
    
    sort(cow.begin(),cow.end());
    vl interval;
    
    if(cow[0].s=="S") interval.pb(1);
    for(int i=0; i<n-1; i++) {
        if(cow[i].s==cow[i+1].s) continue;
        ll temp=cow[i].f+cow[i+1].f;
        if(cow[i].s=="NS" && temp%2!=0) {
            temp=(temp/2)+1;
            interval.pb(temp);
        }
        else {
            temp/=2;
            interval.pb(temp);
        }
    }
    if(cow[n-1].s=="S")  interval.pb(1e9);
    
    //use to print out physical representations of the intervals
    /* for(int i=0; i<interval.size(); i++) {
        if(i%2==0) cout<<"["<<interval[i]<<",";
        else cout<<interval[i]<<"] ";
    }
    cout<<"\n";
    */
    
    ll count=0;
    
    for(int i=0; i<interval.size(); i+=2) {
        ll start,end;
        start=interval[i];
        end=interval[i+1];
        
        if((start<a && end<a) || (start>b && end>b)) continue;
        if(start<a) start=a;
        if(end>b) end=b;
        
        count+=end-start+1;
    }

    cout<<count<<"\n";
    return 0;
}
