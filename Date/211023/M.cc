#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    int n;
    cin >> n;

    int64_t sum = 0;

    while (n--) {
        int idx;
        cin >> idx;

        if (idx == 63) {
            sum += e;
        } else if (idx >= 61) {
            sum += d;
        } else if (idx >= 57) {
            sum += c;
        } else if (idx >= 49) {
            sum += b;
        } else {
            sum += a;
        }
    }

    cout << 10000 * sum << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    for (int TwT = 1; TwT <= T; ++TwT) {
        cout << "Case #" << TwT << ": ";
        solve();
    }

    return 0;
}