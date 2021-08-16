#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    ifstream cin ("split.in");
    ofstream cout ("split.out");
    
    int N; cin >> N;
    
    vector<pair<int, int> > cow(N);
    
    for (auto& [x, y] : cow) cin >> x >> y;
    
    // vertical divider
    sort(cow.begin(), cow.end());
    
    // monotonic queue to keep track of max and min, we can also use a suffix max and min array as well
    deque<int> dqMax, dqMin;
    
    for (int i = 0; i < N; ++i) {
        auto [ignore, y] = cow[i];
        while (!dqMax.empty() && cow[dqMax.back()].second <= y) dqMax.pop_back();
        while (!dqMin.empty() && cow[dqMin.back()].second >= y) dqMin.pop_back();
        dqMax.push_back(i);
        dqMin.push_back(i);
    }
    
    ll one_enclosure = 1LL * (cow[N-1].first - cow[0].first) * (cow[dqMax.front()].second - cow[dqMin.front()].second);
    
    ll ans = 0;
    
    int yMin = INT_MAX, yMax = INT_MIN;
    
    for (int i = 0; i < N - 1; ++i) {
        auto [x, y] = cow[i];
        yMax = max(yMax, y);
        yMin = min(yMin, y);
        if (cow[i].first == cow[i+1].first) continue; // same x-coordinate
        while (dqMax.front() <= i) dqMax.pop_front(); 
        while (dqMin.front() <= i) dqMin.pop_front();
        ans = max(ans, one_enclosure - 1LL * (x - cow[0].first) * (yMax - yMin) - 1LL * (cow[N-1].first - cow[i+1].first) * (cow[dqMax.front()].second - cow[dqMin.front()].second));
    }
    
    dqMax.clear();
    dqMin.clear();
    
    // horizontal divider
    sort(cow.begin(), cow.end(), [&](pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });
    
    for (int i = 0; i < N; ++i) {
        auto [x, ignore] = cow[i];
        while (!dqMax.empty() && cow[dqMax.back()].first <= x) dqMax.pop_back();
        while (!dqMin.empty() && cow[dqMin.back()].first >= x) dqMin.pop_back();
        dqMax.push_back(i);
        dqMin.push_back(i);
    }
    
    int xMin = INT_MAX, xMax = INT_MIN;
    
    for (int i = 0; i < N - 1; ++i) {
        auto [x, y] = cow[i];
        xMin = min(xMin, x);
        xMax = max(xMax, x);
        if (cow[i].second == cow[i+1].second) continue; // same y-coordinate
        while (dqMax.front() <= i) dqMax.pop_front();
        while (dqMin.front() <= i) dqMin.pop_front();
        ans = max(ans, one_enclosure - 1LL * (y - cow[0].second) * (xMax - xMin) - 1LL * (cow[N-1].second - cow[i+1].second) * (cow[dqMax.front()].first - cow[dqMin.front()].first));
    }
    
    cout << ans << '\n';

    return 0;
}
