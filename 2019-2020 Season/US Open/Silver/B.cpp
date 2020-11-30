#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pi = pair<int, int>;
using vpi = vector<pi>;
using indexed_set = tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>;
 
const ll INF = 1e18;
const int MOD = 1e9+7;

const int mxN = 1e5 + 1;
int N, M, ans = 0;
int cur[mxN];
int choice[mxN][2];
queue<int> nextInLine[mxN];

void reorganize(int cereal) {
	
	if(nextInLine[cereal].empty()) return;
	
	int cow = nextInLine[cereal].front();
	nextInLine[cereal].pop();
	
	if(cur[choice[cow][0]] == cow) {
		reorganize(cereal);
	}
	else if(cur[choice[cow][1]] == cow) {
		cur[cereal] = cow;
		reorganize(choice[cow][1]);
	}
	else {
		cur[cereal] = cow;
		++ans;
	}
}
 
int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ifstream cin ("cereal.in");
	ofstream cout ("cereal.out");
	
	cin >> N >> M;
	for(int i = 1 ; i <= N; ++i) {
		
		int a, b;
		cin >> a >> b;
		choice[i][0] = a;
		choice[i][1] = b;
		
		if(cur[a] == 0) {
			++ans;
			cur[a] = i;
			continue;
		}
		else nextInLine[a].push(i);
		if(cur[b] == 0) {
			++ans;
			cur[b] = i;
			continue;
		}
		else nextInLine[b].push(i);
	}
	
	cout << ans << '\n';
	
	for(int remove = 1; remove < N; ++remove) {
		int a = choice[remove][0], b = choice[remove][1];
		if(cur[a] == remove) {
			--ans;
			reorganize(a);
		}
		else if(cur[b] == remove) {
			--ans;
			reorganize(b);
		}
		cout << ans << '\n';
	}
	
	return 0;
}
