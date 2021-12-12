#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    if (std::abs(a - b) > 1 || a + b > n - 2) {
        cout << "-1\n";
        return;
    } else {
        vector<int> ans(n);
        iota(ans.begin(), ans.end(), 1);

        if (a < b) {
            for (int i = 0; i < n - 1 && b--; i += 2) {
                swap(ans[i], ans[i + 1]);
            }

        } else if (a > b) {
            for (int i = n - 1; i > 0 && a--; i -= 2) {
                swap(ans[i], ans[i - 1]);
            }
        } else {
            for (int i = 1; i < n - 1 && a--; i += 2) {
                swap(ans[i], ans[i + 1]);
            }
        }

        for (int &x : ans) {
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