#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t n, a, b;
    int64_t p, q, r, s;

    cin >> n >> a >> b;
    cin >> p >> q >> r >> s;

    for (int64_t i = p; i <= q; ++i) {
        for (int64_t j = r; j <= s; ++j) {
            if (i - a == j - b || i - a == b - j) {
                cout << '#';
            } else {
                cout << '.';
            }
        }
        cout << '\n';
    }


    return 0;
}