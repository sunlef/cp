#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, d;
    cin >> n >> d;
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        int spend = mid + ceil(1.0 * d / (mid + 1));
        if (spend <= n) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    int spend = l + ceil(1.0 * d / (l + 1));
    if (spend <= n) {
        cout << "yes\n";
    } else {
        cout << "no\n";
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