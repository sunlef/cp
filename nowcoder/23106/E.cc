#include <bits/stdc++.h>
using namespace std;

void solve() {
    int64_t N, M;
    cin >> N >> M;

    if (M == 1 && N != 1) {
        cout << "-1\n";
        return;
    }
    
    int64_t l = 0, r = 1e9;
    while (l < r) {
        int64_t mid = (l + r) / 2;
        if (mid * (M - 1) >= N - M) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << 2 * l + 1 << '\n';
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