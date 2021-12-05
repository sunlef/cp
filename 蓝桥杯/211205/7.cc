#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int64_t> a(3);
    for (int64_t &ai : a) {
        cin >> ai;
    }

    sort(a.begin(), a.end());
    if (a[0] * a[0] + a[1] * a[1] == a[2] * a[2]) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}