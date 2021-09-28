#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    priority_queue<pair<int, int>> q;

    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        q.push(make_pair(x, i));
    }

    vector<pair<int, int>> ans;
    while (!q.empty()) {
        while (!q.empty() && q.top().first == 0) {
            q.pop();
        }
        if (q.empty()) {
            break;
        }
        auto A = q.top();
        q.pop();
        while (!q.empty() && q.top().first == 0) {
            q.pop();
        }
        if (q.empty()) {
            break;
        }
        auto B = q.top();
        q.pop();
        ans.push_back(make_pair(A.second, B.second));
        --A.first, --B.first;
        if (A.first) {
            q.push(A);
        }
        if (B.first) {
            q.push(B);
        }
    }

    cout << ans.size() << '\n';
    for (auto &[x, y] : ans) {
        cout << x << ' ' << y << '\n';
    }
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