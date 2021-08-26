#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    ifstream cin ("art2.in");
    ofstream cout ("art2.out");
    
    int N; cin >> N;
    vector<int> l(N+1, -1), r(N+1, -1);

    vector<int> paint(N);

    for (int i = 0; i < N; ++i) {
        cin >> paint[i];
        if (paint[i] == 0) continue;
        if (l[paint[i]] == -1) l[paint[i]] = i;
        r[paint[i]] = i;
    }

    int ans = 0;
    stack<int> stk;

    for (int i = 0; i < N; ++i) {
        int color = paint[i];
        if (color == 0 && !stk.empty()) {
            cout << "-1\n";
            return 0;
        }
        if (l[color] == i) stk.push(color);
        ans = max(ans, (int)stk.size());
        if (r[color] == i) {
            if (stk.top() != color) {
                cout << "-1\n";
                return 0;
            }
            stk.pop();
        }
    }

    cout << ans << '\n';

    return 0;
}
