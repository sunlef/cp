#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &i : a) {
        cin >> i;
    }

    bool ok1 = true, ok2 = true;
    for (int i = 2; i < n; i += 2) {
        ok1 &= (a[i] % 2) == (a[0] % 2);
    }
     for (int i = 3; i < n; i += 2) {
        ok2 &= (a[i] % 2) == (a[1] % 2);
    }

    if (ok1 && ok2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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