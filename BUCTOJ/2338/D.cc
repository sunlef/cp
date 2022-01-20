#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    while (cin >> a >> b) {
        if (max(a, b) < 11) {
            if (((a + b) / 2) % 2 == 0) {
                cout << "A\n";
            } else {
                cout << "B\n";
            }
        } else {
            if (max(a, b) - min(a, b) >= 2) {
                cout << "Game Over\n";
            } else {
                cout << (b > a ? "A\n" : "B\n");
            }
        }
    }

    return 0;
}