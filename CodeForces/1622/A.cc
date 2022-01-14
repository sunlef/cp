#include <bits/stdc++.h>
using namespace std;

void solve() {
    vector<int> a(3);
    for (int &i : a) {
        cin >> i;
    }

    ranges::sort(a);

    if (a[0] + a[1] == a[2]) {
        cout << "YES\n";
        return;
    }

    if (a[0] == a[1]) {
        if (a[2] % 2 == 0) {
            cout << "YES\n";
            return;
        }
    }

    if (a[1] == a[2]) {
        if (a[0] % 2 == 0) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int TwT = 1; TwT <= T; ++TwT) {
        solve();
    }

    return 0;
}