#include <bits/stdc++.h>

void solve() {
    int a, b, c;
    std::cin >> a >> b >> c;

    if (std::set<int>({a, b, c}).size() <= 1) {
        if (a == 0) {
            std::cout << "YES\n1 1 1\n";
        } else {
            std::cout << "NO\n";
        }
        return;
    }

    int64_t x, y, z, k;
    if (b > a) {
        k = std::max(0, (c - a) / b) + 1;
        x = k * b + a;
        y = b;
        z = (k * b + a) * 2 + c;
    } else if (a > c) {
        k = std::max(0, (b - c) / a) + 1;
        x = a;
        y = (k * a + c) * 2 + b;
        z = k * a + c;
    } else {
        k = std::max(0, (a - b) / c) + 1;
        x = (k * c + b) * 2 + a;
        y = k * c + b;
        z = c;
    }

    std::cout << "YES\n" << x << ' ' << y << ' ' << z << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    for (int TwT = 1; TwT <= T; ++TwT) {
        solve();
    }

    return 0;
}