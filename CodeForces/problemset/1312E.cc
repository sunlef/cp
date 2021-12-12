#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector a(n, vector(n, INT_MIN));
    vector f(n, vector(n, INT_MAX));

    for (int i = 0; i < n; ++i) {
        cin >> a[i][i];
        f[i][i] = 1;
    }

    for (int len = 1; len <= n; ++len) {
        for (int l = 0, r = len - 1; r < n; ++l, ++r) {
            for (int mid = l; mid + 1 <= r; ++mid) {
                f[l][r] = min(f[l][r], f[l][mid] + f[mid + 1][r]);
                if (a[l][mid] == a[mid + 1][r] && a[l][mid] != INT_MIN) {
                    a[l][r] = a[l][mid] + 1;
                    f[l][r] = 1;
                }
            }
        }
    }

    cout << f[0][n - 1] << '\n';

    return 0;
}