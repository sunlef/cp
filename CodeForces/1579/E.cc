#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    deque<int> q;
    while (n--) {
        int x;
        cin >> x;
        if (q.empty()) {
            q.push_back(x);
        } else if (x < q.front()) {
            q.push_front(x);
        } else {
            q.push_back(x);
        }
    }

    for (auto x : q) {
        cout << x << ' ';
    }
    cout << '\n';
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