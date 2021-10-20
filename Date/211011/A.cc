#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;

    while (cin >> n) {
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            res |= n % i;
        }
        cout << res << '\n';
    }

    return 0;
}