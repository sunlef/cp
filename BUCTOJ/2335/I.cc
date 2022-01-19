#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    array<int, 3> a;

    while (cin >> a[0] >> a[1] >> a[2]) {
        sort(a.begin(), a.end());
        if (a[0] + a[1] <= a[2]) {
            cout << "ERROR\n";
        } else if (a[0] == a[1] && a[1] == a[2]) {
            cout << "DB\n";
        } else if (a[0] == a[1] || a[0] == a[2] || a[1] == a[2]) {
            cout << "DY\n";
        } else if (a[0] * a[0] + a[1] * a[1] == a[2] * a[2]) {
            cout << "ZJ\n";
        } else {
            cout << "PT\n";
        }
    }

    return 0;
}