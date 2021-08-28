#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    cin >> N;
    using i64 = long long;
    vector<i64> a(2 * N + 1), pre(2 * N + 1);

    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    for (int i = N + 1; i <= 2 * N; ++i) {
        a[i] = a[i - N];
        pre[i] = pre[i - 1] + a[i];
    }

    auto check = [&](i64 x) -> bool {
        for (int i = 1; i <= N; ++i) {
            auto pos1 = lower_bound(pre.begin() + i, pre.end(), pre[i] + x) - pre.begin();
            auto pos2 = lower_bound(pre.begin() + pos1, pre.end(), pre[pos1] + x) - pre.begin();
            auto pos3 = lower_bound(pre.begin() + pos2, pre.end(), pre[pos2] + x) - pre.begin();
            if (pos3 <= N + i) {
                return true;
            }
        }
        return false;
    };

    i64 l = 0, r = (pre[N] + 2) / 3;
    while (l < r) {
        i64 mid = (l + r + 1) >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    cout << l << '\n';

    return 0;
}