#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    cin >> N;
    using i64 = long long;
    i64 a[2 * N + 1], pre[2 * N + 1];

    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    for (int i = N + 1; i <= 2 * N; ++i) {
        a[i] = a[i - N];
        pre[i] = pre[i - 1] + a[i];
    }

    i64 l = 0, r = pre[N] / 3 + 2, ans = r;

    auto check = [&](i64 x) -> bool {
        for (int i = 1; i <= N; ++i) {
            auto begin = pre + i, end = pre + 2 * N + 1;
            auto pos = lower_bound(begin, end, pre[i - 1] + x) - pre + 1;
            begin = pre + pos;
            pos = lower_bound(begin, end, pre[pos - 1] + x) - pre + 1;
            begin = pre + pos;
            pos = lower_bound(begin, end, pre[pos - 1] + x) - pre + 1;
            if (pos <= N + i) {
                return true;
            }
        }
        return false;
    };

    while (l <= r) {
        i64 mid = (l + r) >> 1;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << '\n';

    return 0;
}