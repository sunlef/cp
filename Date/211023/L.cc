#include <bits/stdc++.h>
using namespace std;

void solve() { 
    int n;
    cin >> n;

    if (n < 7) {
        cout << "Draw\n";
    } else if (n < 16) {
        if (n % 2 == 1) {
            cout << "Panda\n";
        } else {
            cout << "Draw\n";
        }
    } else {
        if (n % 2 == 1) {
            cout << "Panda\n";
        } else {
            cout << "Sheep\n";
        }
    }

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    for (int TwT = 1; TwT <= T; ++TwT) {
        cout << "Case #" << TwT << ": ";
        solve();
    }

    return 0;
}