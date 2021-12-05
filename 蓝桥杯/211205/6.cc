#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t p, t;
    cin >> p >> t;

    int64_t l = 0, r = 10000;
    while (l < r) {
        int64_t mid = (l + r) / 2;
        if (mid * 12 >= t) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l * p << '\n';

    return 0;
}