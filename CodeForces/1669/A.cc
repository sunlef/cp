#include <bits/stdc++.h>
using namespace std;

void solve() {
    int r;
    cin >> r;

    if (r >= 1900) {
        cout << "Division 1";
    } else if (r >= 1600) {
        cout << "Division 2";
    } else if (r >= 1400) {
        cout << "Division 3";
    } else {
        cout << "Division 4";
    }

    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int QvQ = 1; QvQ <= T; ++QvQ) {
        solve();
    }

    return 0;
}