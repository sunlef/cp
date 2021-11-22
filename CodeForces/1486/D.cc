#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }

    int l = 1, r = n;

    auto check = [&](int x) -> bool {
        vector<int> mn(n + 1, INT_MAX), pre(n + 1);
        mn[0] = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i - 1] >= x) {
                pre[i] = pre[i - 1] + 1;
            } else {
                pre[i] = pre[i - 1] - 1;
            }
            mn[i] = min(mn[i - 1], pre[i]);
        }
        for (int i = k; i <= n; ++i) {
            if (pre[i] - mn[i - k] > 0) {
                return true;
            }
        }
        return false;
    };

    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    cout << l << '\n';
    return 0;
}