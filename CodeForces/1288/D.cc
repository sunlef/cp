#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector arr(n, vector<int>(m));
    for (auto &row : arr) {
        for (auto &x : row) {
            cin >> x;
        }
    }

    int ansi, ansj;
    auto check = [&](int x) -> bool {
        vector<int> mask(1 << m, -1);
        for (int i = 0; i < n; ++i) {
            int res = 0;
            for (int j = 0; j < m; ++j) {
                if (arr[i][j] >= x) {
                    res |= 1 << j;
                }
            }
            mask[res] = i;
        }

        for (int i = 0; i < (1 << m); ++i) {
            if (mask[i] == -1) {
                continue;
            }
            for (int j = 0; j < (1 << m); ++j) {
                if (mask[j] == -1) {
                    continue;
                }
                if ((i | j) == (1 << m) - 1) {
                    ansi = mask[i], ansj = mask[j];
                    return true;
                }
            }
        }

        return false;
    };

    int l = 0, r = 1e9;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    cout << ansi + 1 << ' ' << ansj + 1 << '\n';

    return 0;
}