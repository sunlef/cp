#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;

    while (cin >> K) {
        for (int y = K + 1; y <= 2 * K; ++y) {
            if (K * y % (y - K) == 0) {
                cout << "1/" << K << "=1/" << (K * y / (y - K)) << "+1/" << y << '\n';
            }
        }
    }

    return 0;
}