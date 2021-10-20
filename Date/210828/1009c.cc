#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    pair<int, int> pr = make_pair(0, 0);
    map<pair<int, int>, int> mp;
    mp[make_pair(0, 0)] = 1;

    int64_t ans = 0;

    for (auto &ch : s) {
        int x = pr.first, y = pr.second;

        if (ch == 'L') {
            --x;
        } else if (ch == 'R') {
            ++x;
        } else if (ch == 'U') {
            ++y;
        } else {
            --y;
        }

        pr = make_pair(x, y);
        int &t = mp[pr];
        ans += t;
        ++t; 
    }

    cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    for (int TwT = 1; TwT <= T; ++TwT) {
        solve();
    }

    return 0;
}