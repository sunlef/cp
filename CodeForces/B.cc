#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    vector<int> ans;
    ans.push_back(a);
    vector<int> visited(n + 1);
    visited[a] = visited[b] = 1;

    for (int i = 0; i < n / 2 - 1; ++i) {
        for (int j = n; j >= 1; --j) {
            if (!visited[j] && (j > a)) {
                ans.push_back(j);
                visited[j] = 1;
                break;
            }
        }
    }

    ans.push_back(b);
    for (int i = 0; i < n / 2 - 1; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (!visited[j] && (j < b)) {
                ans.push_back(j);
                visited[j] = 1;
                break;
            }
        }
    }

    if (ans.size() != n) {
        cout << "-1\n";
    } else {
        for (auto &x : ans) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int TwT = 1; TwT <= T; ++TwT) {
        solve();
    }

    return 0;
}