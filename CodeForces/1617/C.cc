#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> A(n);

    for (int &ai : A) {
        cin >> ai;
    }

    ranges::sort(A);

    vector<int> B;
    deque<bool> vis(n + 1);
    for (int &ai : A) {
        if (ai >= 1 && ai <= n && !vis[ai]) {
            vis[ai] = true;
        } else {
            B.push_back(ai);
        }
    }

    int ans = 0;

    for (int i = n; i >= 1; --i) {
        if (vis[i]) {
            continue;
        }
        if (B.size() == 0) {
            cout << "-1\n";
            return;
        }
        int bi = B.back();
        B.pop_back();

        int r = (bi - 1) / 2;
        if (i <= r) {
            vis[i] = true;
        }

        ++ans;
    }

    cout << ((ranges::count_if(vis, [](bool x) { return x == true; }) == n) ? ans : -1) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    std::cin >> T;
    for (int TwT = 1; TwT <= T; ++TwT) {
        solve();
    }

    return 0;
}