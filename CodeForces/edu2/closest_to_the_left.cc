#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (auto& x : a) {
        cin >> x;
    }

    auto check = [&](int x) -> int {
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (a[mid] <= x) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }

        if (a[l] <= x) {
            return l;
        } else {
            return -1;
        }
    };

    while (k--) {
        int x;
        cin >> x;
        cout << check(x) + 1 << '\n';
    }

    return 0;
}