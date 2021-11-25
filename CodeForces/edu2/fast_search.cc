#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    ranges::sort(a);

    auto find_low = [&](int x) -> int {
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (a[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (a[l] >= x) {
            return l;
        } else {
            return n;
        }
    };

    auto find_up = [&](int x) -> int {
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (a[mid] > x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (a[l] > x) {
            return l;
        } else {
            return n;
        }
    };

    int k;
    cin >> k;
    while (k--) {
        int l, r;
        cin >> l >> r;
        cout << find_up(r) - find_low(l) << ' ';
    }
    cout << '\n';

    return 0;
}