#include <bits/stdc++.h>
using namespace std;

void solve() {
    vector<int> a(7);
    for (int &ai : a) {
        cin >> ai;
    }
    ranges::sort(a);

    if (a[0] + a[1] == a[2]) {
        cout << a[0] << ' ' << a[1] << ' ' << a[3] << '\n';
    } else {
        cout << a[0] << ' ' << a[1] << ' ' << a[2] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    std::cin >> T;
    for (int TwT = 1; TwT <= T; ++TwT) {
        solve();
    }

    return 0;
}