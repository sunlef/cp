#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto check = [](int64_t x) -> bool {
        for (int64_t i = 0; i <= 10000; ++i) {
            for (int64_t j = 0; j <= 10000; ++j) {
                if (i * i - j * j == x) {
                    return true;
                }
            }
        }
        return false;
    };

    int res = 0;
    for (int64_t i = 1; i <= 2021; ++i) {
        if (check(i)) {
            cout << i << '\n';
            ++res;
        }
    }
    cout << res << '\n';
    return 0;
}