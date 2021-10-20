#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    srand(time(0) * time(0));

    unsigned t = 1;
    cout << t << endl;
    for (int i = 1; i <= t; ++i) {
        cout << 1000 << '\n';
        for (int j = 1; j <= 1000; ++j) {
            unsigned a = rand() % 4;
            if (a == 0) {
                cout << 'U';
            } else if (a == 1) {
                cout << 'D';
            } else if (a == 2) {
                cout << 'L';
            } else {
                cout << 'R';
            }
        }
        cout << '\n';
    }

    return 0;
}